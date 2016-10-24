//
// Created by Jorge Henrique Piazentin Ono on 10/22/16.
//

#include "Triangle.h"

Triangle::Triangle(Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d p3, std::shared_ptr<Material> material):p1(p1), p2(p2), p3(p3), Surface(material){
    Eigen::Vector3d u,v;
    u = p2 - p1;
    v = p3 - p1;
    n1 = u.cross(v);
    n2 = n1;
    n3 = n1;
}

double Triangle::hit(const Ray &ray){
    double xa, xb, xc, xd, xe, ya, yb, yc, yd, ye, za, zb, zc, zd, ze;
    double a, b, c, d, e, f, g, h, i, j, k, l, m, alpha, beta, gamma, t;
    xa = p1(0);
    xb = p2(0);
    xc = p3(0);
    xd = ray.direction(0);
    xe = ray.origin(0);
    ya = p1(1);
    yb = p2(1);
    yc = p3(1);
    yd = ray.direction(1);
    ye = ray.origin(1);
    za = p1(2);
    zb = p2(2);
    zc = p3(2);
    zd = ray.direction(2);
    ze = ray.origin(2);
    a = xa - xb;
    b = ya - yb;
    c = za - zb;
    d = xa - xc;
    e = ya - yc;
    f = za - zc;
    g = xd;
    h = yd;
    i = zd;
    j = xa - xe;
    k = ya - ye;
    l = za - ze;
    m = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);

    if (m == 0) return -1;

    t = - (f*(a*k-j*b) + e*(j*c - a*l) + d*(b*l - k*c))/m;

    beta = (j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g))/m;
    gamma = (i*(a*k-j*b) + h*(j*c - a*l) + g*(b*l-k*c))/m;

    if (gamma < 0 || gamma > 1)
        return -1;

    if (beta < 0 || beta > 1-gamma)
        return -1;

    return t;
}

Eigen::Vector3d Triangle::normal(const Eigen::Vector3d point) {
    Eigen::Vector3d na,nb;
    Eigen::Vector3d n  = (p2-p1).cross(p3-p1);
    double alpha, beta, gamma;
    double sqnorm = n.squaredNorm();
    na = (p3-p2).cross(point-p2);
    nb = (p1-p3).cross(point-p3);
    alpha = n.dot(na)/sqnorm;
    beta = n.dot(nb)/sqnorm;
    gamma = 1 - alpha - beta;
    return (alpha * n1 + beta * n2 + gamma * n3).normalized();
}
