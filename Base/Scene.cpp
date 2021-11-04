//
// Created by sieri on 04/11/2021.
//

#include "Scene.h"

Scene::Scene(const Camera& camera) : camera(camera){

}

void Scene::addMesh(const Mesh& mesh) {
    meshs.push_back(mesh);
}

void Scene::render(std::array<int, 2> res) {
    //do the magic
}
