//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#include "Material.h"

Material::Material() {

}

Material::Material( Eigen::Vector4d surface_color,  Eigen::Vector4d specular_color,  double specular_decay,
                   double reflection_constant) :
surface_color(surface_color), specular_color(specular_color), specular_decay(specular_decay), reflection_constant(reflection_constant){
}