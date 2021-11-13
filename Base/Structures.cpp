//
// Created by sieri on 04/11/2021.
//
#include "Structures.h"
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

Vec3::Vec3(const std::array<double, 3>& values):values(values){

}

double Vec3::norm() {
    return sqrt(values[0] * values[0]+ values[1] * values[1] +values[2]*values[2]);
}

Vec3 Vec3::divide(double divider) {
    Vec3 result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = this->values[i]/divider;
    }
    return result;
}

Vec3::Vec3() : values({0,0,0}){

}

Vec3 Vec3::operator+(const Vec3 &vec) {
    Vec3 result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = this->values[i]+vec.values[i];
    }
    return result;
}

double Vec3::x() const {
    return values[0];
}

double Vec3::y() const {
    return values[1];
}

double Vec3::z() const {
    return values[2];
}

Vec3 Vec3::operator-(const Vec3 &vec) {
    Vec3 result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = this->values[i]-vec.values[i];
    }
    return result;
}

double Vec3::dot(const Vec3 &vec) {
    double result=0;
    for (int i = 0; i < 3; ++i) {
        result += this->values[i]*vec.values[i];
    }
    return result;
}

Vec3 Vec3::rotateX(double theta) {
    return Vec3({
        x(),
        y()* cos(theta)- z()*sin(theta),
        y()* sin(theta)+ z()*cos(theta)} );
}

Vec3 Vec3::rotateY(double theta) {
    return Vec3({
        x()* cos(theta)+ z()*sin(theta),
        y(),
        -x()* sin(theta)+ z()*cos(theta)});
}

Vec3 Vec3::rotateZ(double theta) {
    return Vec3({
        x()* cos(theta)- y()*sin(theta),
        x()* sin(theta)+ y()*cos(theta),
        z()} );
}

Vec3 Vec3::rotate(double alpha, double beta, double theta)
{
    double m11 = cos(alpha)*cos(beta);
    double m12 = cos(alpha)*sin(beta)*sin(theta)-sin(alpha)*cos(theta);
    double m13 = cos(alpha)*sin(beta)*cos(theta)+sin(alpha)*sin(theta);

    double m21 = sin(alpha)*cos(beta);
    double m22 = sin(alpha)*sin(beta)*sin(theta)+cos(alpha)*cos(theta);
    double m23 = sin(alpha)*sin(beta)*cos(theta)-cos(alpha)*sin(theta);

    double m31 = -sin(beta);
    double m32 = cos(beta)*sin(alpha);
    double m33 = cos(beta)*sin(theta);

    return Vec3({
        x()*m11+y()*m12+z()*m13,
        x()*m21+y()*m22+z()*m23,
        x()*m31+y()*m32+z()*m33,
    });

}

Ray::Ray(const Vec3 &origin, const Vec3 &direction, int pixelX, int pixelY): origin(origin), direction(direction), pixelX(pixelX), pixelY(pixelY) {

}

int Ray::getPixelX() const {
    return pixelX;
}

int Ray::getPixelY() const {
    return pixelY;
}
