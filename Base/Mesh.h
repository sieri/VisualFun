//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_MESH_H
#define VISUALFUN_MESH_H

#include <vector>
#include "Face.h"
#include "Vec3.h"

class Mesh {
private:
    Vec3 origine;
public:
    explicit Mesh(std::vector<Face>  faces);

    std::vector<Face> faces;
};


#endif //VISUALFUN_MESH_H
