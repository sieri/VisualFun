#include <iostream>
#include <opencv2/opencv.hpp>
#include "Base/Mesh.h"
#include "Base/Camera.h"
#include "Base/Scene.h"

int main() {

    Mesh a({
        Face({-1.0,0.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,0.0}),
        Face({-1.0,0.0,0.0}, {0.0,1.0,0.5}, {0.0,0.0,1.0}),
        Face({-1.0,0.0,0.0}, {0.0,1.0,0.5}, {0.0,0.0,1.0}),
        Face({0.0,1.0,0.5}, {1.0,0.0,0.0}, {0.0,0.0,1.0}),
        });

    Camera cam({0.0,0.5,0.0}, 90);

    Scene scene(cam);

    scene.addMesh(a);

    scene.render({10,10});

    return 0;
}
