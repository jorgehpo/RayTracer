//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Ray.h"

Ray::Ray(const Eigen::Vector3d origin, const Eigen::Vector3d direction):origin(origin), direction(direction) {
}

std::string Ray::toString() {
    std::ostringstream s;
    s << "(" << origin.transpose() << ")" << " (" << direction.transpose() << ")" << std::endl;
    return s.str();
}