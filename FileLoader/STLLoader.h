//
// Created by sieri on 16/11/2021.
//

#ifndef VISUALFUN_STLLOADER_H
#define VISUALFUN_STLLOADER_H


#include <string>
#include "../Scene/Mesh.h"

union convertToFloat
{
    float fval;
    uint8_t intval[4];
};

class STLLoader {
public:
    STLLoader(std::string fileName);

    Mesh read();
private:
    std::string fileName;
    std::vector<uint8_t>* data;
    std::array<double, 3> getVertex(int start_index);

};


#endif //VISUALFUN_STLLOADER_H
