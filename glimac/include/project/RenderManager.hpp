#pragma once
#include <iostream>
#include "AppManager.hpp"
#include "../glimac/TrackballCamera.hpp"
#include "../glimac/Plane.hpp"
#include "../glimac/SDLWindowManager.hpp"
#include "../glimac/Sphere.hpp"
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Plane.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Geometry.hpp>
#include <cstddef>
#include <glimac/FreeflyCamera.hpp>
#include "../../include/glimac/Image.hpp"


#ifndef IMACGL_RENDERMANAGER_H
#define IMACGL_RENDERMANAGER_H


class RenderManager {

private:

    std::map<std::string,GLuint>textures; //textures des planètes
    std::map<std::string,GLuint>texturesSatellites; // textures des satellites
    glimac::Sphere* MySphere; // sphère
    TrackballCamera Camera; // caméra
    AppManager* app; // application
    bool displaySun; // boolean indiquant si on doit afficher tout le système solaire ou une seule planètes
    std::map<std::string, Planete>::iterator displayedPlanet; //iterator pour parcourir la map de planètesà afficher
    std::map<std::string, Planete> system; //map contenant les planètes




public:
    //getters
    const std::map<std::string, GLuint> &getTextures() const;
    const GLuint getTexture(std::string name);
    const GLuint getTextureSatellites(std::string name);
    glimac::Sphere *getMySphere() const;

    //setters
    void setTextures( std::map<std::string, GLuint> &textures);
    void setMySphere(glimac::Sphere *MySphere);


    // constructors
    RenderManager();

    //methods
    //void createTexture(GLuint texture, std::unique_ptr<glimac::Image>map); // permet de factoriser le code de création des textures mais map n'est pas accepté comme argument valide...
    void createTexturesPlanets();
    void createtextureSatellites();
    void initRenderManager();
    void initSphere();
    int renderLoop(char* arg);//boucle de rendu
    void Control( glimac::SDLWindowManager* windowManager); // contrôles de la caméra, du zoom et de la vitesse





};


#endif //IMACGL_RENDERMANAGER_H
