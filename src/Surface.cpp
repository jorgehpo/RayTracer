//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Surface.h"

Surface::Surface(const Eigen::Vector4d surface_color, const Eigen::Vector4d specular_color, double specular_decay):
        specular_color(specular_color), surface_color(surface_color), specular_decay(specular_decay) {
}