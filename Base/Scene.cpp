//
// Created by sieri on 04/11/2021.
//

#include "Scene.h"
#include "Vec3.h"
#include "Ray.h"
#include <algorithm>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <thread>

Scene::Scene(const Camera& camera) : camera(camera){

}

void Scene::addMesh(const Mesh& mesh) {
    meshs.push_back(mesh);
}

cv::Mat Scene::render(std::array<int, 2> res) {

    cv::Mat img(res[0],res[1], CV_8U, cv::Scalar(0));




    auto camPos = camera.getPosition();
    //put all the mesh in one
    std::vector<Face> faces;
    for (const auto& m : meshs) {
        for (auto f: m.faces) {
            faces.push_back(f);
        }
    }
    std::sort(faces.begin(), faces.end(), [camPos](Face a, Face b){
        return a.get_distance_from_camera(camPos) > b.get_distance_from_camera(camPos);
    });

    // generate rays
    Vec3 base({0,0,-1});



    auto rayTrace = [&faces, &img, &camPos](int x_start, int x_stop, int y_start, int y_stop, int width, int height
            ) {
        std::vector<Ray> rays;

        for (int x = x_start; x < x_stop; ++x) {
            double pScreenX = 2 * ((x + 0.5) / width) - 1;
            for (int y = y_start; y < y_stop; ++y) {
                double pScreenY = 2 * ((y + 0.5) / width) - 1;
                Vec3 dir({pScreenX, pScreenY, -1.0});
                rays.emplace_back(camPos, dir-camPos, x, height-(y+1));
            }

        }

        for (const auto& r : rays) {

            auto it = std::find_if(faces.begin(), faces.end(), [&](Face face){
                return face.intersect_with(r);
            });

            if (it != faces.end())
            {
                auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());

                color = (*it).getColor();
            }
            else
            {
                auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());
                color = 0;
            }
        }

        return 0;
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < res[0]; ++i) {
        threads.emplace_back(rayTrace, i, i+1, 0, res[1], res[0], res[1]);
    }

    for (auto &t : threads) {
        t.join();
    }

    return img;
}
