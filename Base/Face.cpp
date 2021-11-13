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
    update();
}

Vec3 Face::get_normal() {
    return Vec3({a,b,c});
}

Vec3 Face::get_normalised_normal() {
    Vec3 normal = get_normal();
    return normal.divide(normal.norm());
}

bool Face::intersect_with(const Ray &r) {
    double k = this->intersect_length(r);
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
    return - (r.origin.x()*a+r.origin.y()*b+r.origin.z()*c+d)/(a* r.direction.values[0] +b*r.direction.values[1]+c*r.direction.values[2]);
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

