//
// Created by Jorge Henrique Piazentin Ono on 10/16/16.
//

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt,
                                     const Eigen::Vector3d up, const double d, const double width, const double height,
                                     const unsigned int nx, const unsigned int ny):
        BaseCamera(position, lookAt, up, width, height, nx, ny), d(d){
}

Ray PerspectiveCamera::ray(const unsigned int i, const unsigned int j){
    double _u, _v;
    _u = l + (r-l)*(i + 0.5)/nx;
    _v = b + (t-b)*(j + 0.5)/ny;
    return Ray(e, -d*w + u*_u + v*_v);
}

