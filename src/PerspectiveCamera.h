//
// Created by Jorge Henrique Piazentin Ono on 10/16/16.
//

#ifndef RAYTRACER_PERSPECTIVECAMERA_H
#define RAYTRACER_PERSPECTIVECAMERA_H

#include "BaseCamera.h"

class PerspectiveCamera:public BaseCamera {
    double d;
public:
    PerspectiveCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up, const double d,
                      const double width=500, const double height=500, const unsigned int nx=500, const unsigned int ny = 500);
    Ray ray( unsigned int i, unsigned int j);
};


#endif //RAYTRACER_PERSPECTIVECAMERA_H
