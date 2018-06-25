#pragma once
#include <iostream>
#include "AppManager.hpp"
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Plane.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Geometry.hpp>
#include <cstddef>
#include <glimac/FreeflyCamera.hpp>


#ifndef IMACGL_RENDERMANAGER_H
#define IMACGL_RENDERMANAGER_H


class RenderManager {

private:
    glimac::SDLWindowManager* windowManager;
    std::map<std::string,GLuint>textures;
    std::map<std::string,GLuint>texturesSatellites;
    std::map<std::string,glm::mat4>Matrix;
    glimac::Sphere* MySphere;
    glimac::Plane* MyPlane;
    TrackballCamera Camera;




public:
    //getters
    const std::map<std::string, GLuint> &getTextures() const;
    const GLuint getTexture(std::string name);
    const GLuint getTextureSatellites(std::string name);
    glimac::Sphere *getMySphere() const;
    glimac::SDLWindowManager *getWindowManager() const;
    glimac::Plane *getMyPlane() const;

    //setters
    void setTextures( std::map<std::string, GLuint> &textures);
    void setMySphere(glimac::Sphere *MySphere);
    void setWindowManager(glimac::SDLWindowManager *windowManager);
    void setMyPlane(glimac::Plane *MyPlane);




    // constructors
    RenderManager();

    //methods
    void createTexturesPlanets();
    void createtextureSatellites();
    void displayPlanet( Planete p);
    void initRenderManager();
    void initWindowManager(int width, int height, const char* name);
    void initSphere();
    void initPlane();
    void initMatrix();
    int renderLoop(GLuint vao,AppManager* app);



};


#endif //IMACGL_RENDERMANAGER_H
