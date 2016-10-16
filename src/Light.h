//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Eigen/Core"

class Light {
public:
    double I, p; //Intensity of light and power of specular decay
    Eigen::Vector3d position;
    Eigen::Vector4d color;
    Light(const double I, const Eigen::Vector3d position, const Eigen::Vector4d color);
};


#endif //RAYTRACER_LIGHT_H
