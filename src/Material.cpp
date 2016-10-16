//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#include "Material.h"

Material::Material() {

}

Material::Material(const Eigen::Vector4d surface_color, const Eigen::Vector4d specular_color,
                   const double specular_decay) :
surface_color(surface_color), specular_color(specular_color), specular_decay(specular_decay){
}