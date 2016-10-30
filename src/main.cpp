#define STB_IMAGE_WRITE_IMPLEMENTATION // Do not include this line twice in your project!
// C++ include
#include <iostream>
#include <string>
#include <vector>
#include "stb_image_write.h"
#include "utils.h"
#include "Scene.h"
#include "Image.h"
#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"

// Shortcut to avoid Eigen:: and std:: everywhere, DO NOT USE IN .h
using namespace std;
using namespace Eigen;

int main()
{
    auto c = make_shared<PerspectiveCamera>(Eigen::Vector3d(-1, 0, -5), Eigen::Vector3d(0,0,0), Eigen::Vector3d(0,1,0), 5,  5, 5, 1000, 1000);
    //auto c = make_shared<OrthographicCamera>(Eigen::Vector3d(0, -3, 0), Eigen::Vector3d(0,0,0), Eigen::Vector3d(0,1,1), 5,  5, 1000, 1000);

    Scene s;

    Image i = s.render(c);

    // Save to png
    write_matrix_to_png(i.R, i.G, i.B, i.A, "teste.png");



    return 0;
}
