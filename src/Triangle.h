//
// Created by Jorge Henrique Piazentin Ono on 10/22/16.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "Surface.h"
#include "Material.h"
#include "Ray.h"
#include <memory>
#include <Eigen/core>
#include <Eigen/Geometry>

class Triangle: public Surface {
private:
    Eigen::Vector3d p1, p2, p3, n1, n2, n3;
public:
    Triangle(Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d p3, std::shared_ptr<Material> material);
    double hit(const Ray &ray);
};


#endif //RAYTRACER_TRIANGLE_H
