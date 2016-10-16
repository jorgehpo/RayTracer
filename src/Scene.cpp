//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Scene.h"

Scene::Scene(){
    ambient_light.color = Eigen::Vector4d(1,1,1,1);
    ambient_light.I = 0.1;
    //surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(-1,-1,0), 1.0, Eigen::Vector4d(1.0,0,0,1)));
    //lights.push_back(std::make_shared<Light>(1, Eigen::Vector3d(-5, -5, -5), Eigen::Vector4d(1,1,1,1)));
}


Image Scene::render(OrthographicCamera camera) {

    Sphere s1 = Sphere(Eigen::Vector3d(1, 1, 0), 1.0, Eigen::Vector4d(1.0, 0, 0, 1), Eigen::Vector4d(1.0, 1.0, 1.0, 1),
                       10);

    Image image(camera.nx, camera.ny);

    Light light(1, Eigen::Vector3d(-5, 5, -5), Eigen::Vector4d(1, 1, 1, 1));


    unsigned int i, j;
    for (i = 0; i < camera.nx; ++i){
        for (j = 0; j < camera.ny; ++j){
            Ray ray = camera.ray(i,j);
            double t1 = s1.hit(ray);
            if ((t1 > 0)){
                Eigen::Vector3d p = ray.origin + ray.direction * t1;
                Eigen::Vector3d n = s1.normal(p);
                n.normalize();
                Eigen::Vector3d l = light.position - p;
                l.normalize();
                Eigen::Vector3d v = (camera.getPosition() - p).normalized();
                Eigen::Vector3d h = (v + l).normalized();
                Eigen::Vector4d L = light.I * light.color.cwiseProduct(s1.surface_color) * std::max(0.0, n.dot(l)) + \
                light.I * light.color.cwiseProduct(s1.specular_color) * std::pow(std::max(0.0, n.dot(h)), s1.specular_decay) + \
                ambient_light.color.cwiseProduct(s1.surface_color)*ambient_light.I;
                image.R(i,j) = L(0);
                image.G(i,j) = L(1);
                image.B(i,j) = L(2);
            }
        }
    }
    return image;
}

void Scene::setAmbient(Eigen::Vector4d color, double I) {
    ambient_light.color = color;
    ambient_light.I = I;
}