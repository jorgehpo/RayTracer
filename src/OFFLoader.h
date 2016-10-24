//
// Created by Jorge Henrique Piazentin Ono on 10/23/16.
//

#ifndef RAYTRACER_OFFLOADER_H
#define RAYTRACER_OFFLOADER_H

#include <memory>
#include "Triangle.h"
#include "Eigen/Core"
#include <fstream>
#include <vector>
#include "Material.h"
#include <iostream>
#include <sstream>

class OFFLoader {
public:
    OFFLoader();
    std::vector<std::shared_ptr<Triangle>> loadOFFMesh(std::string filename, Eigen::Matrix4d transform, std::shared_ptr<Material> material);
};


#endif //RAYTRACER_OFFLOADER_H
