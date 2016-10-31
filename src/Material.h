//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Eigen/Core"

class Material {
public:
    Eigen::Vector4d surface_color, specular_color;
    double specular_decay, reflection_constant;
    Material();
    Material( Eigen::Vector4d surface_color,  Eigen::Vector4d specular_color,  double specular_decay,
                 double reflection_constant=0);
};


#endif //RAYTRACER_MATERIAL_H
