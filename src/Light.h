//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Eigen/Core"

class Light {
public:
    double k_d;
    Eigen::Vector4d color;
    Eigen::Vector3d position;
};


#endif //RAYTRACER_LIGHT_H
