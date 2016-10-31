//
// Created by Jorge Henrique Piazentin Ono on 10/14/16.
//

#include "Scene.h"

Scene::Scene(){
    ambient_light.color = Eigen::Vector4d(1,1,1,1);
    ambient_light.I = 0.1;
    std::shared_ptr<Material> mRed = std::make_shared<Material>(Eigen::Vector4d(1.0, 0, 0, 1),
                                                             Eigen::Vector4d(0.7, 0.7, 0.7, 1), 100, .3);

    std::shared_ptr<Material> mBlue = std::make_shared<Material>(Eigen::Vector4d(0.0, 0, 1.0, 1),
                                                             Eigen::Vector4d(0.7, 0.7, 0.7, 1), 100, .3);

    std::shared_ptr<Material> mGreen = std::make_shared<Material>(Eigen::Vector4d(0.0, 1.0, 0, 1),
                                                                 Eigen::Vector4d(0.7, 0.7, 0.7, 1), 100, .3);

    std::shared_ptr<Material> mGray = std::make_shared<Material>(Eigen::Vector4d(0.6, 0.6, 0.6, 1),
                                                                  Eigen::Vector4d(0.3, 0.3, 0.3, 1), 100, .7);


    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(1, 1, 5), 0.8, mRed));

    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(-1, 2, 3), 0.8, mBlue));

    surfaces.push_back(std::make_shared<Sphere>(Eigen::Vector3d(-1, 1, 0), 0.8, mGreen));

    lights.push_back(std::make_shared<Light>(0.5, Eigen::Vector3d(-5, 15, -5), Eigen::Vector4d(1, 1, 1, 1)));

    //lights.push_back(std::make_shared<Light>(1, Eigen::Vector3d( 15, 5, 5), Eigen::Vector4d(1, 1, 1, 1)));

    lights.push_back(std::make_shared<Light>(1, Eigen::Vector3d( -3, 10,-3), Eigen::Vector4d(1, 1, 1, 1)));

    surfaces.push_back(std::make_shared<Triangle>(Eigen::Vector3d (-20,-1.5,-20), Eigen::Vector3d (20,-1.5,-20), Eigen::Vector3d (20,-1.5,20), mGray));
    surfaces.push_back(std::make_shared<Triangle>(Eigen::Vector3d (-20,-1.5,20), Eigen::Vector3d (-20,-1.5,-20), Eigen::Vector3d (20,-1.5,20), mGray));

    //Eigen::Matrix4d transform = Eigen::MatrixXd::Identity(4,4);
    //OFFLoader offloader;
    //std::vector<std::shared_ptr<Triangle>> triangles = offloader.loadOFFMesh("bunny.off", transform, mRed);
   // surfaces.insert(surfaces.end(), triangles.begin(), triangles.end());

}


Image Scene::render(std::shared_ptr<BaseCamera> camera, unsigned int raytracing_depth) {
    this->camera = camera;

    std::vector<std::thread> threads;

    Image image(camera->nx, camera->ny);

    unsigned int n_threads = std::thread::hardware_concurrency();

    std::cout << "n_threads = " << n_threads;

    /* Algorithm for subdividing an array into “semi-equal”, uniform sub-arrays
     *
     * http://stackoverflow.com/questions/8084010/algorithm-for-subdividing-an-array-into-semi-equal-uniform-sub-arrays
     *
     * If your language has integer division that truncates,
     * an easy way to compute the size of section i is via (N*i+N)/M - (N*i)/M.
     * For example, the python program
     * N=100;M=12
     * for i in range(M): print (N*i+N)/M - (N*i)/M
     * outputs the numbers 8 8 9 8 8 9 8 8 9 8 8 9
     *
     */


    auto render_t = [this, n_threads, &image](int t){
        unsigned int begin = (this->camera->nx * t)/n_threads;
        unsigned int end = (this->camera->nx * (t+1))/n_threads;

        for (unsigned int i = begin; i < end; ++i){
            for (unsigned int j = 0; j < this->camera->ny; ++j){
                Ray ray = this->camera->ray(i,j);
                Eigen::Vector4d c = this->rayColor(ray, 15);
                image.R(i,j) = (c(0) > 1? 1: c(0));
                image.G(i,j) = (c(1) > 1? 1: c(1));
                image.B(i,j) = (c(2) > 1? 1: c(2));
            }
        }
    };

    for (unsigned int t = 0; t < n_threads; t++){
        threads.push_back(std::thread(render_t, t));
    }

    for ( std::thread& t : threads)
        t.join();

    return image;
}

void Scene::setAmbient(Eigen::Vector4d color, double I) {
    ambient_light.color = color;
    ambient_light.I = I;
}

Eigen::Vector4d Scene::rayColor(Ray ray, unsigned int niter) {
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
        Eigen::Vector4d c(0,0,0,0);

        for (auto light = lights.begin(); light != lights.end(); ++light){
            Eigen::Vector3d l = ((*light)->position - p).normalized();
            Eigen::Vector3d v = (camera->getPosition() - p).normalized();
            Eigen::Vector3d h = (v + l).normalized();
            Eigen::Vector3d p2 = p + l*1e-10;
            bool hit = false;
            Ray ray_light(p2,l);
            for (auto object = surfaces.begin(); object != surfaces.end(); ++object){
                double _t = (*object)->hit(ray_light);
                if (_t > 0){
                    hit = true;
                    break;
                }
            }
            if (!hit){
                c = c + (*light)->I * (*light)->color.cwiseProduct(s->material->surface_color) * std::max(0.0, n.dot(l)) + \
                (*light)->I * (*light)->color.cwiseProduct(s->material->specular_color) * std::pow(std::max(0.0, n.dot(h)), s->material->specular_decay);
                if (s->material->reflection_constant > 0 && niter > 1){
                    Eigen::Vector3d reflection_direction = ray.direction - 2 * (ray.direction.dot(n)) *n;
                    Eigen::Vector3d reflection_p = p + reflection_direction * 1e-10;
                    Ray r {reflection_p, reflection_direction};
                    c = c  + s->material->reflection_constant*rayColor(r, niter-1);
                }
            }
        }
        c = c +  ambient_light.color.cwiseProduct(s->material->surface_color)*ambient_light.I;
        return c;
    }
    return Eigen::Vector4d(0,0,0,0);
}
