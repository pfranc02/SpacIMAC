#define GLEW_STATIC
#include <glimac/SDLWindowManager.hpp>
#include <iostream>
#include "../glimac/include/project/RenderManager.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    RenderManager *render = new RenderManager(); //création du moteur de rendu
    render->renderLoop(argv[0]); //boucle de rendu
 }
