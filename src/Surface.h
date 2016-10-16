//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H

#include "Eigen/Core"
#include "Ray.h"

class Surface {
public:
    Eigen::Vector4d surface_color, specular_color;
    double specular_decay;
    Surface(const Eigen::Vector4d surface_color, const Eigen::Vector4d specular_color, double specular_decay);
    virtual double hit(const Ray &ray) = 0;
    virtual Eigen::Vector3d normal(const Eigen::Vector3d point) = 0;
};


#endif //RAYTRACER_SURFACE_H
