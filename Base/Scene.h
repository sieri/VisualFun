//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_SCENE_H
#define VISUALFUN_SCENE_H

#include "Camera.h"
#include "Mesh.h"
#include "Face.h"
#include <opencv2/opencv.hpp>

class Scene {

public:
    explicit Scene(const Camera& camera);
    void addMesh(const Mesh& mesh);
    cv::Mat render(std::array<int, 2> res);
private:
    Camera camera;
    std::vector<Mesh> meshs;

};


#endif //VISUALFUN_SCENE_H
