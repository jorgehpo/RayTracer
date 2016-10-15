//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Sphere.h"

Sphere::Sphere(const Eigen::Vector3d center, const double radius, const Eigen::Vector4d color):
        center(center), radius(radius), Surface(color) {
}

double Sphere::intersect(const Ray &ray) {
    //solution from Foundations of Computer Graphics, 4th edition, page 77
    Eigen::Vector3d originMinusCenter = ray.origin - center; // origin of ray minus center of sphere
    double z = ray.direction.dot(originMinusCenter);
    double dDotD = ray.direction.dot(ray.direction);
    double discriminant = z*z - dDotD * (originMinusCenter.dot(originMinusCenter) - radius*radius);
    if (discriminant < 0){
        return -1;
    }
    double sqrtDet = sqrt(discriminant);
    if (z*z > sqrtDet){
        return (-z - sqrtDet)/dDotD;
    }else{
        return (-z - sqrtDet)/dDotD;
    }
}

Eigen::Vector3d Sphere::normal(const Eigen::Vector3d point) {
    return (point - center)/radius;
}