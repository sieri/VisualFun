//
// Created by sieri on 25/11/2021.
//

#include "Matrix.h"

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list){

    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            values[k][l] = list.begin()[k].begin()[l];
        }
    }


}


Vec3 Matrix::multiply(Vec3 vec) const{
    std::array<double, 3> valArray{0,0,0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            valArray[i]+= this->values.at(i).at(j)*vec.getValues().at(j);
        }
    }
    return Vec3(valArray);
}

