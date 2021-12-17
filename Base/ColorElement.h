//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_COLOR_ELEMENTs_H
#define VISUALFUN_COLOR_ELEMENT_H


#include <opencv2/opencv.hpp>

class Scene {

public:
    explicit ColorElement(const cv::Vec3b color, double albedo);
    void addMesh(const Mesh& mesh);
    cv::Mat render(std::array<int, 2> res);


private:
    cv::Vec3b color;
    double albedo;


};


#endif //VISUALFUN_SCENE_H
