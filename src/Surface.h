//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H

#include "Eigen/Core"
#include "Ray.h"
#include "Material.h"
#include <memory>

class Surface {
public:
    std::shared_ptr<Material> material;
    Surface(std::shared_ptr<Material> material);
    virtual double hit(const Ray &ray) = 0;
    virtual Eigen::Vector3d normal(const Eigen::Vector3d point) = 0;
};


#endif //RAYTRACER_SURFACE_H
