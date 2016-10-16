//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#include "Light.h"

Light::Light(const double I, const Eigen::Vector3d position, const Eigen::Vector4d color)
        : I(I), position(position), color(color) {
}