//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_SCENE_H
#define VISUALFUN_SCENE_H

#include "Camera.h"
#include "Mesh.h"
#include "Structures.h"

class Scene {

public:
    explicit Scene(const Camera& camera);
    void addMesh(const Mesh& mesh);
    void render(std::array<int, 2> res);
private:
    Camera camera;
    std::vector<Mesh> meshs;

};


#endif //VISUALFUN_SCENE_H
