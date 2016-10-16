//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_BASECAMERA_H
#define RAYTRACER_BASECAMERA_H

#include "Eigen/Core"
#include "Eigen/Geometry"
#include "Ray.h"
#include <sstream>

class BaseCamera {
protected:
    Eigen::Vector3d position, lookAt, up;
    Eigen::Vector3d e, u, v, w; // e: position, u: right, v:up, w:back
    double l, r, t, b; //left, right, top, bottom
    double width, height; //width, height of the image plane
public:
    unsigned int nx, ny; //size of the image
    BaseCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up,
               const double width, const double height, const unsigned int nx, const unsigned int ny);
    Eigen::Vector3d getPosition();
    std::string toImagePlaneString();
};


#endif //RAYTRACER_BASECAMERA_H
