//
// Created by sieri on 04/11/2021.
//

#include "Scene.h"
#include "../Base/Vec3.h"
#include "../Base/Ray.h"
#include <algorithm>
#include <thread>
#include <thread>
#include <cmath>

Scene::Scene(const Camera& camera) : camera(camera){

}

void Scene::addMesh(const Mesh& mesh) {
    meshs.push_back(mesh);
}

cv::Mat Scene::render(std::array<int, 2> res) {

    cv::Mat img(res[0],res[1], CV_8U, cv::Scalar(0));




    auto camPos = camera.getCameraToWorld().multiply(camera.getPosition());

    //put all the mesh in one
    std::vector<Face> faces;
    for (const auto& m : meshs) {
        for (auto f: m.faces) {
            faces.push_back(f);
        }
    }
    std::sort(faces.begin(), faces.end(), [camPos](Face a, Face b){
        return a.get_distance_from_camera(camPos) < b.get_distance_from_camera(camPos);
    });

    auto fov = this->camera.getFov();


    //raytracing lambda
    auto rayTrace = [&](int x_start, int x_stop, int y_start, int y_stop, int width, int height) {
        std::vector<Ray> rays;

        for (int x = x_start; x < x_stop; ++x) {

            double pScreenX = (2 * ((x + 0.5) / width) - 1)* tan(fov/2);
            for (int y = y_start; y < y_stop; ++y) {
                double pScreenY = (1 - 2 * ((y + 0.5) / height)) * tan(fov/2);
                Vec3 dir({pScreenX, pScreenY, 1.0});
                dir = this->camera.getCameraToWorld().multiply(dir);
                rays.emplace_back(camPos, dir, x, y);
            }
        }

        for (const auto& r : rays) {

            auto it = std::find_if(faces.begin(), faces.end(), [&](Face face){
                return face.intersect_with(r);
            });

            if (it != faces.end())
            {
                auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());

                color = (*it).getColor() * sin((*it).intersect_angle(r));
            }
            else
            {
                auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());
                color = 0;
            }
        }

        return 0;
    };

    //get the number of processors
    const auto processor_count = std::thread::hardware_concurrency();

    std::cout << processor_count << std::endl;

    //generate threads of raytracing, once per line
    std::vector<std::thread> threads;
    
    int line_per_thread = res[0] / processor_count;

    std::cout << line_per_thread << std::endl;

    for (int i = 0; i < processor_count-1; ++i) {
        threads.emplace_back(rayTrace, line_per_thread*i, line_per_thread*i+line_per_thread, 0, res[1], res[0], res[1]);
    }

    threads.emplace_back(rayTrace, line_per_thread* (processor_count - 1), res[0], 0, res[1], res[0], res[1]);

    //wait for the tread to finish
    for (auto &t : threads) {
        t.join();
    }

    return img;
}
