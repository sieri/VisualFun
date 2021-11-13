//
// Created by sieri on 04/11/2021.
//
#include "BasicGeometry.h"
#include <cmath>
double triangleArea(Vec3 a, Vec3 b, Vec3 c)
{
    auto ab = (a-b);
    auto ac = (a-c);
    auto ab_norm = ab.norm();
    auto ac_norm = ac.norm();
    auto dot_prod = ab.dot(ac);
    return sqrt(ab_norm*ab_norm*ac_norm*ac_norm-dot_prod*dot_prod)/2;
}
