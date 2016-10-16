//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Scene.h"

Scene::Scene(){
    ambient_light.color = Eigen::Vector4d(1,1,1,1);
    ambient_light.I = 0.1;
    std::shared_ptr<Material> mRed = std::make_shared<Material>(Eigen::Vector4d(1.0, 0, 0, 1),
                                                             Eigen::Vector4d(0.7, 0.7, 0.7, 1), 10);

    std::shared_ptr<Material> mBlue = std::make_shared<Material>(Eigen::Vector4d(0.0, 0, 1.0, 1),
                                                             Eigen::Vector4d(0.7, 0.7, 0.7, 1), 10);

    std::shared_ptr<Material> mGreen = std::make_shared<Material>(Eigen::Vector4d(0.0, 1.0, 0, 1),
                                                                 Eigen::Vector4d(0.7, 0.7, 0.7, 1), 10);

    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(1, 1, 0), 0.8, mRed));

    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(-1, -1, 0), 0.8, mBlue));

    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(-1, 1, 0), 0.8, mGreen));

    lights.push_back(std::make_shared<Light>(1, Eigen::Vector3d(-5, 5, -5), Eigen::Vector4d(1, 1, 1, 1)));

    lights.push_back(std::make_shared<Light>(1, Eigen::Vector3d( 5, 5, 5), Eigen::Vector4d(1, 1, 1, 1)));
}

template <typename C>
Image Scene::render(C camera) {

    Image image(camera.nx, camera.ny);


    unsigned int i, j;


    for (i = 0; i < camera.nx; ++i){
        for (j = 0; j < camera.ny; ++j){
            Ray ray = camera.ray(i,j);
            double t = std::numeric_limits<double>::infinity();
            std::shared_ptr<Surface> s;
            for (auto object = surfaces.begin(); object != surfaces.end(); ++object){
                double _t = (*object)->hit(ray);
                if (_t >= 0 && _t < t){
                    t = _t;
                    s = *object;
                }
            }
            if (s){ //if object is not null
                Eigen::Vector3d p = ray.origin + ray.direction * t;
                Eigen::Vector3d n = s->normal(p);
                Eigen::Vector4d L(0,0,0,0);

                for (auto light = lights.begin(); light != lights.end(); ++light){
                    Eigen::Vector3d l = ((*light)->position - p).normalized();
                    Eigen::Vector3d v = (camera.getPosition() - p).normalized();
                    Eigen::Vector3d h = (v + l).normalized();
                    L = L + (*light)->I * (*light)->color.cwiseProduct(s->material->surface_color) * std::max(0.0, n.dot(l)) + \
                (*light)->I * (*light)->color.cwiseProduct(s->material->specular_color) * std::pow(std::max(0.0, n.dot(h)), s->material->specular_decay) + \
                ambient_light.color.cwiseProduct(s->material->surface_color)*ambient_light.I;
                }

                image.R(i,j) = L(0);
                image.G(i,j) = L(1);
                image.B(i,j) = L(2);
            }
        }
    }
    return image;
}

template Image Scene::render(PerspectiveCamera camera);
template Image Scene::render(OrthographicCamera camera);

void Scene::setAmbient(Eigen::Vector4d color, double I) {
    ambient_light.color = color;
    ambient_light.I = I;
}