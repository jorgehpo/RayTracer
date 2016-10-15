//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H

#include "Eigen/Core"
#include "Ray.h"

class Surface {
protected:
    Eigen::Vector4d color;
public:
    Surface(const Eigen::Vector4d color);
    virtual double intersect(const Ray &ray) = 0;
};


#endif //RAYTRACER_SURFACE_H
