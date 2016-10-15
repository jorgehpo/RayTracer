//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Scene.h"

Scene::Scene() {
    //Red sphere centered at the origin
    Sphere s(Eigen::Vector3d(0,0,0), 1.0, Eigen::Vector4d(1.0,0,0,1));
    //Camera positioned at 0,0,-5 looking at origin
    OrtographicCamera c(Eigen::Vector3d(0,0,-5), Eigen::Vector3d(0,0,0), Eigen::Vector3d(0,1,0), 10, 10, 50, 50);
    //std::cout<< "Intersect: "<< s.intersect(c.ray(25,25)) << std::endl;
    std::cout<< "ray: "<< c.ray(0,0).toString() << std::endl;
}