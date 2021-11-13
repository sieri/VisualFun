//
// Created by sieri on 04/11/2021.
//

#include "Mesh.h"
#include "Vec3.h"

#include <utility>

Mesh::Mesh(std::vector<Face> faces):faces(std::move(faces)), origine({0,0,0}){

}
