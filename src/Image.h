//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include "Eigen/Core"

class Image {
public:
    Eigen::MatrixXd R, G, B, A;
    Image(const unsigned int nx, const unsigned int ny, const double r=0, const double g=0, const double b=0, const double a=1);
};


#endif //RAYTRACER_IMAGE_H
