#define GLEW_STATIC
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Geometry.hpp>
#include <cstddef>
#include <vector>
#include "../glimac/include/project/AppManager.hpp"
using namespace glimac;
/*
int main(int argc, char** argv) {
    AppManager *app = new AppManager();
    app->initier_system();
    std::cout<< "okinitier" << std:: endl;
    std::cout <<app->getAstre("Soleil").getRot_propre() << std::endl;

}*/