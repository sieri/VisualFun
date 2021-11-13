//
// Created by sieri on 04/11/2021.
//

#include "Scene.h"
#include <algorithm>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
Scene::Scene(const Camera& camera) : camera(camera){

}

void Scene::addMesh(const Mesh& mesh) {
    meshs.push_back(mesh);
}

cv::Mat Scene::render(std::array<int, 2> res) {

    cv::Mat img(res[0],res[1],CV_8U);

    //put all the mesh in one
    std::vector<Face> faces;
    for (const auto& m : meshs) {
        for (auto f: m.faces) {
            faces.push_back(f);
        }
    }

    // generate rays
    Vec3 base({0,0,-1});

    std::vector<Ray> rays;
    for (int x = 0; x < res[0]; ++x) {
        double PscreenX = 2*((x+0.5)/res[0])-1;
        for (int y = 0; y < res[1]; ++y) {
            double PscreenY = 2*((y+0.5)/res[1])-1;
            Vec3 dir({PscreenX, PscreenY,-1.0});
            rays.emplace_back(camera.getPosition(), dir-camera.getPosition(), x, res[1]-y);
        }
    }

    for (const auto& r : rays) {

        auto it = std::find_if(faces.begin(), faces.end(), [&](Face face){
            return face.intersect_with(r);
        });

        if (it != faces.end())
        {
            auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());
            color = 255;
        }
        else
        {
            auto  &color = img.at<uchar>(r.getPixelY(), r.getPixelX());
            color = 0;
        }
    }

    return img;
}
