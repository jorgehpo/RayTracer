// C++ include
#include <iostream>
#include <string>
#include <vector>

// Image writing library
#define STB_IMAGE_WRITE_IMPLEMENTATION // Do not include this line twice in your project!
#include "stb_image_write.h"
#include "utils.h"
#include "Scene.h"
#include "Image.h"
#include "PerspectiveCamera.h"

// Shortcut to avoid Eigen:: and std:: everywhere, DO NOT USE IN .h
using namespace std;
using namespace Eigen;

int main()
{

    PerspectiveCamera c(Eigen::Vector3d(0, 0, -5), Eigen::Vector3d(0,0,0), Eigen::Vector3d(0,1,0), 5,  5, 5, 2000, 2000);

    Scene s;

    Image i = s.render(c);

    // Save to png
    write_matrix_to_png(i.R, i.G, i.B, i.A, "teste.png");
    return 0;
}
