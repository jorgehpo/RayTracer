//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Eigen/Core"

class Material {
public:
    Eigen::Vector4d surface_color, specular_color;
    double specular_decay;
    Material();
    Material(const Eigen::Vector4d surface_color, const Eigen::Vector4d specular_color, const double specular_decay);
};


#endif //RAYTRACER_MATERIAL_H
