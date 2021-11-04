//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_MESH_H
#define VISUALFUN_MESH_H

#include <vector>
#include "Structures.h"

class Mesh {
private:
    std::vector<Face> faces;
    Vertex origine;
public:
    explicit Mesh(std::vector<Face>  faces);
};


#endif //VISUALFUN_MESH_H
