//
// Created by sieri on 13/11/2021.
//


#include <cmath>
#include "Vec3.h"


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

Vec3::Vec3() : values({0, 0, 0}){

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

Vec3 Vec3::rotate(double alpha, double beta, double theta) const
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

const std::array<double, 3> &Vec3::getValues() const {
    return values;
}

Vec3 Vec3::operator*(const Vec3 &vec) const {
    return Vec3({this->y()*vec.z() - this->z()*vec.y(),
                 this->z()*vec.x() - this->x()*vec.z(),
                this->x()*vec.y() - this->y()*vec.x()});
}
