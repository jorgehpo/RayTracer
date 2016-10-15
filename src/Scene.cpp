//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Scene.h"

Scene::Scene() {
}


Image Scene::render(OrthographicCamera camera) {
    //Red sphere centered at the origin
    Sphere s(Eigen::Vector3d(0,0,0), 1.0, Eigen::Vector4d(1.0,0,0,1));

    Image image(camera.nx, camera.ny);

    Light light;

    light.k_d=0.1;
    light.color = Eigen::Vector4d(1,1,1,1);
    light.position = Eigen::Vector3d(5,5,-10);


    unsigned int i, j;
    for (i = 0; i < camera.nx; ++i){
        for (j = 0; j < camera.ny; ++j){
            Ray ray = camera.ray(i,j);
            double t = s.intersect(ray);
            if (t > 0){
                Eigen::Vector3d p = ray.origin + ray.direction * t;
                Eigen::Vector3d n = s.normal(p);
                Eigen::Vector3d l = (light.position - p);
                l.normalized();
                Eigen::Vector4d L = light.k_d * light.color.cwiseProduct(s.color) * std::max(0.0, n.dot(l));
                image.R(i,j) = L(0);
                image.G(i,j) = L(1);
                image.B(i,j) = L(2);
            }
        }
    }
    return image;
}