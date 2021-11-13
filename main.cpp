#include <iostream>
#include <opencv2/opencv.hpp>
#include "Base/Mesh.h"
#include "Base/Camera.h"
#include "Base/Scene.h"
#include <cmath>
int main() {

    {
        Face f(Vec3({0.0,0,0}),
        Vec3({0,1,0}),
        Vec3({1,0,0}));

        Ray r(Vec3({0.5,0.5,-0.5}), Vec3({0,0,1}),1,1);
    }


    Mesh a({
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,0.0,1.0}), Vec3({1.0,0.0,0.0})),
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,1.0,0.5}), Vec3({0.0,0.0,1.0})),
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,1.0,0.5}), Vec3({0.0,0.0,1.0})),
        Face(Vec3({0.0,1.0,0.5}), Vec3({1.0,0.0,0.0}), Vec3({0.0,0.0,1.0})),
        });

    Camera cam(Vec3({0.0,0.5,-2}), M_PI/2);

    Scene scene(cam);

    scene.addMesh(a);

    auto img = scene.render({1000,1000});

    cv::imshow("Result", img);
    cv::waitKey(0);
    return 0;
}
