//
// Created by sieri on 04/11/2021.
//

#include "Mesh.h"
#include "../Base/Vec3.h"

#include <utility>

Mesh::Mesh(std::vector<Face> faces):origin({0,0,0}), faces(std::move(faces)){

}
