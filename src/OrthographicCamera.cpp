//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up, const double width,
    const double height, const unsigned int nx, const unsigned int ny):BaseCamera(position, lookAt, up, width, height, nx, ny){
    l = -width/2;
    r = width/2;
    t = height/2;
    b = -height/2;
}

Ray OrthographicCamera::ray(const unsigned int i, const unsigned int j){
    double _u, _v;
    _u = l + (r-l)*(i + 0.5)/nx;
    _v = b + (t-b)*(j + 0.5)/ny;
    return Ray(e + _u*u + _v*v, -w);
}