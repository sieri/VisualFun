//
// Created by sieri on 25/11/2021.
//

#ifndef VISUALFUN_MATRIX_H
#define VISUALFUN_MATRIX_H

#include <array>
#include "Vec3.h"
class Matrix {
public:


    Matrix(std::initializer_list<std::initializer_list<double>> list);

    Vec3 multiply(Vec3 vec) const;


private:
    std::array<std::array<double ,3> , 3> values;
};


#endif //VISUALFUN_MATRIX_H
