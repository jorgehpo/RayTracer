//
// Created by Jorge Henrique Piazentin Ono on 10/15/16.
//

#include "Image.h"

Image::Image(const unsigned int nx, const unsigned int ny, const double r, const double g, const double b, const double a) {
    R = Eigen::MatrixXd::Ones(nx,ny) * r;
    G = Eigen::MatrixXd::Ones(nx,ny) * g;
    B = Eigen::MatrixXd::Ones(nx,ny) * b;
    A = Eigen::MatrixXd::Ones(nx,ny) * a;
}