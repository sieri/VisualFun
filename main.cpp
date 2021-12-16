#include <iostream>
#include <opencv2/opencv.hpp>
#include "Scene/Mesh.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Base/Vec3.h"
#include "FileLoader/STLLoader.h"
#include <math.h>
#include <thread>
#include <filesystem>

int main() {




    std::string filename = "C:\\Users\\sieri\\Desktop\\Utah_teapot_(solid)2.stl";
  //  std::string filename = "/home/sieri/Desktop/Utah_teapot_(solid)2.stl";
    STLLoader loader(filename);

   // auto a = loader.read();




    Mesh a({
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,0.0,1.0}), Vec3({1.0,0.0,0.0}),128),
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,1.0,0.5}), Vec3({0.0,0.0,1.0}),255),
        Face(Vec3({-1.0,0.0,0.0}), Vec3({0.0,1.0,0.5}), Vec3({0.0,0.0,1.0}),150),
        Face(Vec3({0.0,1.0,0.5}), Vec3({1.0,0.0,0.0}), Vec3({0.0,0.0,1.0}),50),
        });
      


    Camera cam(Vec3({0.0,4,-10}), M_PI/2);

    Scene scene(cam);

    scene.addMesh(a);

    auto img = scene.render({900,900});

    cv::Mat out;
   // cv::blur(img,out,{2,2});
    cv::imwrite("Result.jpg", img);
    cv::imshow("Result", img);
    cv::waitKey(0);

    return 0;

}
