//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Surface.h"
#include <cmath>

class Sphere:public Surface {
    Eigen::Vector3d center;
    double radius;
public:
    Sphere(const Eigen::Vector3d center, const double radius, const Eigen::Vector4d color);
    double intersect(const Ray &ray);
    Eigen::Vector3d normal(const Eigen::Vector3d point);
};


#endif //RAYTRACER_SPHERE_H
