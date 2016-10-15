//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_ORTOGRAPHICCAMERA_H
#define RAYTRACER_ORTOGRAPHICCAMERA_H

#include "BaseCamera.h"
#include "Ray.h"
#include <iostream>
#include <sstream>

class OrthographicCamera:public BaseCamera {
public:
    OrthographicCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up, const double width=500,
                      const double height=500, const unsigned int nx=500, const unsigned int ny = 500);
    Ray ray(const unsigned int i, const unsigned int j);
};


#endif //RAYTRACER_ORTOGRAPHICCAMERA_H
