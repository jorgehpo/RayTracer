//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Eigen/Core"
#include <sstream>

class Ray {
public:
    Eigen::Vector3d direction, origin;
    Ray(const Eigen::Vector3d origin, const Eigen::Vector3d direction);
    std::string toString();
};


#endif //RAYTRACER_RAY_H
