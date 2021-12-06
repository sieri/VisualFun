//
// Created by sieri on 16/11/2021.
//

#include "STLLoader.h"

#include <utility>
#include <fstream>
#include <iostream>



STLLoader::STLLoader(std::string fileName) : fileName(std::move(fileName)) {

}

Mesh STLLoader::read() {


    // open the file:
    std::ifstream file;
    file.open(fileName, std::ios::binary);

    if (!file.is_open())
    {
        std::cerr << "File not available" << std::endl;
        return Mesh({});
    }

    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    data = new std::vector<uint8_t>(fileSize);
    if ( file.is_open() ) { // always check whether the file is open
        file.read((char*)&(*data)[0], fileSize); // pipe file's content into stream
    }

    uint32_t number_of_triangle = (static_cast<uint32_t>(data->at(83))<<24)+
            (static_cast<uint32_t>(data->at(82))<<16)+
            (static_cast<uint32_t>(data->at(81))<<8)+
            static_cast<uint32_t>(data->at(80));

    std::vector<Face> faces;

    for (int i=0; i<number_of_triangle;i++) { //for each triangle
        int index = 84+12+i*50;
        Vec3 vertex1(getVertex(index));
        index+=12;
        Vec3 vertex2(getVertex(index));
        index+=12;
        Vec3 vertex3(getVertex(index));
        faces.emplace_back(vertex1,vertex2,vertex3);

    }
    delete data;
    return Mesh(faces);
}

std::array<double, 3> STLLoader::getVertex(int start_index) {
    convertToFloat d1{};
    d1.intval[3] = data->at(start_index+3);
    d1.intval[2] = data->at(start_index+2);
    d1.intval[1] = data->at(start_index+1);
    d1.intval[0] = data->at(start_index);

    convertToFloat d2{};
    d2.intval[3] = data->at(start_index+7);
    d2.intval[2] = data->at(start_index+6);
    d2.intval[1] = data->at(start_index+5);
    d2.intval[0] = data->at(start_index+4);

    convertToFloat d3{};
    d3.intval[3] = data->at(start_index+11);
    d3.intval[2] = data->at(start_index+10);
    d3.intval[1] = data->at(start_index+9);
    d3.intval[0] = data->at(start_index+8);

    return {static_cast<double> (d1.fval),static_cast<double> (d2.fval),static_cast<double> (d3.fval)};
}

