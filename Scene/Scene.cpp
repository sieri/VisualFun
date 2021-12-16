//
// Created by sieri on 04/11/2021.
//

#include "Scene.h"
#include "../Base/Vec3.h"
#include "../Base/Ray.h"
#include <algorithm>
#include <thread>
#include <cmath>
#include <filesystem>

Scene::Scene(const Camera& camera) : camera(camera){

    skybox = cv::imread(std::filesystem::current_path().string() + "/imgs/skybox1.jpg");
}

void Scene::addMesh(const Mesh& mesh) {
    meshs.push_back(mesh);
}





cv::Mat Scene::render(std::array<int, 2> res) {

    cv::Mat img(res[0],res[1], CV_8UC3, cv::Scalar(0,0,0));
    //cv::Mat img;
    


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
                auto  &color = img.at<cv::Vec3b>(r.getPixelY(), r.getPixelX());

                color = cv::Vec3b(0,0,(*it).getColor() * sin((*it).intersect_angle(r)));
            }
            else
            {
                auto& color = img.at<cv::Vec3b>(r.getPixelY(), r.getPixelX()); 
                color = skyboxColorAt(r.direction);
            }
        }

        return 0;
    };

    //get the number of processors
    const auto processor_count = std::thread::hardware_concurrency();

    //generate threads of raytracing, once per line
    std::vector<std::thread> threads;
    
    int line_per_thread = res[0] / processor_count;


    for (int i = 0; i < processor_count-1; ++i) {
      threads.emplace_back(rayTrace, line_per_thread*i, line_per_thread*i+line_per_thread, 0, res[1], res[0], res[1]);
      // rayTrace( line_per_thread*i, line_per_thread*i+line_per_thread, 0, res[1], res[0], res[1]);
    }

    threads.emplace_back(rayTrace, line_per_thread* (processor_count - 1), res[0], 0, res[1], res[0], res[1]);

    //wait for the tread to finish
    for (auto &t : threads) {
        t.join();
    }
    //cv::Mat dummy;
    return img;
}

cv::Vec3b Scene::skyboxColorAt(Vec3 dir)
{

    double longitude = (atan2(dir.x(), dir.z()) + M_PI);
    double latitude =acos(dir.y());
    int x = std::min((int)((longitude/M_PI_2) * skybox.cols), skybox.cols-1);
    int y = std::min((int)(latitude/(M_PI_2) * skybox.rows), skybox.rows-1);
  
    //std::cout << latitude *180/M_PI << " ! " << x << ":" << y << std::endl;

   // std::cout << (longitude /2) * skybox.cols << std::endl;

    return skybox.at<cv::Vec3b>(y, x);

}