//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"
#include "Surface.h"
#include "Sphere.h"
#include "Material.h"
#include "Image.h"
#include "Eigen/Core"
#include "Ray.h"
#include "Light.h"
#include <cmath>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

class Scene{
    std::vector <std::shared_ptr<Surface>> surfaces;
    std::vector <std::shared_ptr<Light>> lights;
    struct{
        Eigen::Vector4d color;
        double I;
    }ambient_light;

public:
    Scene();
    template <typename C>
    Image render(C camera);
    void setAmbient(Eigen::Vector4d color, double I);
};


#endif //RAYTRACER_SCENE_H
