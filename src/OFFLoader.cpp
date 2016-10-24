//
// Created by Jorge Henrique Piazentin Ono on 10/23/16.
//

#include "OFFLoader.h"

std::vector<std::shared_ptr<Triangle>>
OFFLoader::loadOFFMesh(std::string filename, Eigen::Matrix4d transform, std::shared_ptr<Material> material) {
    std::vector<std::shared_ptr<Triangle>> triangles;
    std::vector<Eigen::Vector3d> vertices;
    std::string line;
    std::ifstream inputfile(filename);
    std::istringstream ss;
    unsigned int nvert, nface, nedge;
    if (inputfile.is_open()){
        // First line is OFF
        if (!getline(inputfile, line)){
            std::cout << "Error. Empty file.";
            exit(1);
        }

        // Second line is <nvertices> <nfaces> 0
        if (!getline(inputfile, line)){
            std::cout << "Error. No \"<nvertices> <nfaces> 0\" line.";
            exit(1);
        }
        ss.str(line);
        ss >> nvert >> nface >> nedge;

        // Next nvert lines:
        for (unsigned int i = 0; i < nvert; i++){
            if (!getline(inputfile, line)){
                std::cout << "Error. Not enough vertices.";
                exit(1);
            }
            ss.clear();
            ss.str(line);
            double x, y, z;
            ss >> x >> y >> z;
            vertices.push_back(Eigen::Vector3d(x,y,z));
        }

        // Next nface lines:
        unsigned int nv, a, b, c, d;
        for (unsigned int i = 0; i < nface; i++){
            if (!getline(inputfile, line)){
                std::cout << "Error. Not enough faces.";
                exit(1);
            }
            ss.clear();
            ss.str(line);
            ss >> nv;
            if (nv == 3){
                ss >> a >> b >> c;
                triangles.push_back(std::make_shared<Triangle>(vertices[a],vertices[b],vertices[c], material));
            }else if (nv == 4){
                ss >> a >> b >> c >> d;
                triangles.push_back(std::make_shared<Triangle>(vertices[a],vertices[b],vertices[c], material));
                triangles.push_back(std::make_shared<Triangle>(vertices[c], vertices[d], vertices[a],material));
            }else{
                ss.str(line);
                std::cout << "Error. Wrong number of vertices per face: " << nv << std::endl;
                exit(1);
            }
        }
        inputfile.close();
    }else{
        std::cout << "Error loading file";
        exit(1);
    }
    return triangles;
}

OFFLoader::OFFLoader(){

}
