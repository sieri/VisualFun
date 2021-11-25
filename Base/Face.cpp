//
// Created by sieri on 04/11/2021.
//
#include "Face.h"
#include <cmath>
#include <yaml.h>
#include "../Utils/BasicGeometry.h"
#include <iostream>

Face::Face(Vec3 a, Vec3 b, Vec3 c) {
    vertices = {a,b,c};
    this->color = 255;
    update();
}
Face::Face(Vec3 a, Vec3 b, Vec3 c, int color) {
    vertices = {a,b,c};
    this->color = color;
    update();
}
Vec3 Face::get_normal() const{
    return Vec3({a,b,c});
}

Vec3 Face::get_center() const{
    return Vec3({(vertices[0].x()+vertices[1].x()+vertices[2].x())/3,
                 (vertices[0].y()+vertices[1].y()+vertices[2].y())/3,
                (vertices[0].z()+vertices[1].z()+vertices[2].z())/3});
}

double Face::get_distance_from_camera(Vec3 position){
    auto center = get_center();

    return (center - position).norm();
}

bool Face::intersect_with(const Ray &r) {
    double k = this->intersect_length(r);

    if (k < 0)
    {
        return false;
    }

    Vec3 point({
       r.origin.x()+(k*r.direction.x()),
       r.origin.y()+(k*r.direction.y()),
       r.origin.z()+(k*r.direction.z())
    });
    Vec3 A = vertices[0];
    Vec3 B = vertices[1];
    Vec3 C = vertices[2];

    double area1 = triangleArea(A,B,point);
    double area2 = triangleArea(A,C,point);
    double area3 = triangleArea(B,C,point);

    return abs(area-(area1+area2+area3)) < 0.00001;
}

double Face::intersect_length(const Ray &r) const {
    return - (r.origin.x()*a+r.origin.y()*b+r.origin.z()*c+d)/(a* r.direction.x()+b*r.direction.y()+c*r.direction.z());
}

void Face::update() {
    Vec3 A = vertices[0];
    Vec3 B = vertices[1];
    Vec3 C = vertices[2];

    a = (B.y()-A.y())*(C.z()-A.z())-(C.y()-A.y())*(B.z()-A.z());
    b = (B.z()-A.z())*(C.x()-A.x())-(C.z()-A.z())*(B.x()-A.x());
    c = (B.x()-A.x())*(C.y()-A.y())-(C.x()-A.x())*(B.y()-A.y());
    d = -(a*A.x()+b*A.y()+c*A.z());

    area = triangleArea(A,B,C);
}

int Face::getColor() const {
    return color;
}



