//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "OrtographicCamera.h"

OrtographicCamera::OrtographicCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up, const double width,
    const double height, const unsigned int nx, const unsigned int ny):BaseCamera(position, lookAt, up, width, height, nx, ny){
    l = e - u * width/2;
    r = e - u * width/2;
    t = e - v * height/2;
    b = e + v * height/2;
}

Ray OrtographicCamera::ray(const unsigned int i, const unsigned int j){
    Eigen::Vector3d _u, _v;
    _u = l + (r-l)*(i + 0.5)/nx;
    _v = b + (t-b)*(j + 0.5)/ny;
    return Ray(_u + _v, -w);
}