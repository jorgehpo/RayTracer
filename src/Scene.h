//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "OrthographicCamera.h"
#include "Surface.h"
#include "Sphere.h"
#include "Image.h"
#include "Eigen/Core"
#include "Ray.h"
#include "Light.h"

#include <vector>
#include <iostream>
#include <algorithm>

class Scene {
public:
    Scene();
    Image render(OrthographicCamera camera);
};


#endif //RAYTRACER_SCENE_H
