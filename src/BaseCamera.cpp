//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "BaseCamera.h"

BaseCamera::BaseCamera(const Eigen::Vector3d position, const Eigen::Vector3d lookAt, const Eigen::Vector3d up,
                       const double width, const double height, const unsigned int nx, const unsigned int ny):
        position(position), lookAt(lookAt), up(up), width(width), height(height), nx(nx), ny(ny){
    e = position;
    w = -(lookAt - position).normalized();
    v = up.normalized();
    u = w.cross(v);
}

std::string BaseCamera::toImagePlaneString() {
    std::ostringstream s;
    s << "u: " << u.transpose();
    s << std::endl << "v: " << v.transpose();
    s << std::endl << "w: " << w.transpose() << std::endl;
    return s.str();
}
