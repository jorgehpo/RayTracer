//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "BaseCamera.h"
#include "Surface.h"
#include "Sphere.h"
#include "Material.h"
#include "Image.h"
#include "Eigen/Core"
#include <Eigen/Dense>
#include "Ray.h"
#include "Light.h"
#include <cmath>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <thread>
#include "Triangle.h"
#include "OFFLoader.h"


class Scene{
    std::vector <std::shared_ptr<Surface>> surfaces;
    std::vector <std::shared_ptr<Light>> lights;
    struct{
        Eigen::Vector4d color;
        double I;
    }ambient_light;
    Eigen::Vector4d rayColor(Ray ray, unsigned int niter);
    std::shared_ptr<BaseCamera> camera;
public:
    Scene();
    Image render(std::shared_ptr<BaseCamera> camera);
    void setAmbient(Eigen::Vector4d color, double I);
};


#endif //RAYTRACER_SCENE_H
