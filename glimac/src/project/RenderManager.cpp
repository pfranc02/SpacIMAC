#include "project/RenderManager.hpp"

using namespace glimac;

//getters

const std::map<std::string, GLuint> &RenderManager::getTextures() const {
    return textures;
}
const GLuint RenderManager::getTexture(std::string name) {
    return textures[name];
}
Sphere *RenderManager::getMySphere() const {
    return MySphere;
}
Plane *RenderManager::getMyPlane() const {
    return MyPlane;
}
SDLWindowManager *RenderManager::getWindowManager() const {
    return windowManager;
}
const GLuint RenderManager::getTextureSatellites(std::string name) {
    return texturesSatellites[name];
}



//setters
void RenderManager::setTextures( std::map<std::string, GLuint> &textures) {
    RenderManager::textures = textures;
}
void RenderManager::setMySphere(Sphere *MySphere) {
    RenderManager::MySphere = MySphere;
}
void RenderManager::setWindowManager(SDLWindowManager *windowManager) {
    RenderManager::windowManager = windowManager;
}
void RenderManager::setMyPlane(Plane *MyPlane) {
    RenderManager::MyPlane = MyPlane;
}





//constructor
RenderManager::RenderManager() {

}

//methods
void RenderManager::createTexturesPlanets() {

    //Création des texture
    std::unique_ptr<Image> SunMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\sunmap.jpg");
    std::unique_ptr<Image> EarthMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\earthmap.jpg");
    std::unique_ptr<Image> MercuryMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\mercurymap.jpg");
    std::unique_ptr<Image> VenusMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\venusmap.jpg");
    std::unique_ptr<Image> MarsMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\marsmap.jpg");
    std::unique_ptr<Image> JupiterMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\jupitermap.jpg");
    std::unique_ptr<Image> SaturnMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\saturnmap.jpg");
    std::unique_ptr<Image> UranusMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\uranusmap.jpg");
    std::unique_ptr<Image> NeptuneMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\neptunemap.jpg");
    std::unique_ptr<Image> PlutoMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\plutomap.jpg");

    if(SunMap == NULL || EarthMap == NULL||MercuryMap == NULL|| VenusMap == NULL|| MarsMap == NULL || JupiterMap == NULL || SaturnMap == NULL || UranusMap == NULL || NeptuneMap == NULL || PlutoMap == NULL){
        std::cerr << "Une des textures n'a pas pu etre chargée. \n" << std::endl;
        exit(0);
    }
    GLuint textureSun, textureEarth, textureMercury, textureVenus, textureMars, textureJupiter, textureSaturn, textureUranus, textureNeptune, texturePluto;

    //texture Soleil
    glGenTextures(1,&textureSun);
    glBindTexture(GL_TEXTURE_2D,textureSun);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,SunMap->getWidth(),SunMap->getHeight(),0,GL_RGBA,GL_FLOAT,SunMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Sun"] = textureSun;

    //texture Terre
    glGenTextures(1,&textureEarth);
    glBindTexture(GL_TEXTURE_2D,textureEarth);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,EarthMap->getWidth(),EarthMap->getHeight(),0,GL_RGBA,GL_FLOAT,EarthMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Earth"] = textureEarth;

    //texture Mercure
    glGenTextures(1,&textureMercury);
    glBindTexture(GL_TEXTURE_2D,textureMercury);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,MercuryMap->getWidth(),MercuryMap->getHeight(),0,GL_RGBA,GL_FLOAT,MercuryMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Mercury"] = textureMercury;

    //texture Venus
    glGenTextures(1,&textureVenus);
    glBindTexture(GL_TEXTURE_2D,textureVenus);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, VenusMap->getWidth(), VenusMap->getHeight(),0,GL_RGBA,GL_FLOAT, VenusMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Venus"] = textureVenus;


    //texture Mars
    glGenTextures(1,&textureMars);
    glBindTexture(GL_TEXTURE_2D,textureMars);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,MarsMap->getWidth(),MarsMap->getHeight(),0,GL_RGBA,GL_FLOAT,MarsMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Mars"] = textureMars;

    //texture Jupiter
    glGenTextures(1,&textureJupiter);
    glBindTexture(GL_TEXTURE_2D,textureJupiter);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,JupiterMap->getWidth(),JupiterMap->getHeight(),0,GL_RGBA,GL_FLOAT,JupiterMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Jupiter"] = textureJupiter;

    //texture Saturne
    glGenTextures(1,&textureSaturn);
    glBindTexture(GL_TEXTURE_2D,textureSaturn);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,SaturnMap->getWidth(),SaturnMap->getHeight(),0,GL_RGBA,GL_FLOAT,SaturnMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Saturn"] = textureSaturn;

    //texture Uranus
    glGenTextures(1,&textureUranus);
    glBindTexture(GL_TEXTURE_2D,textureUranus);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,UranusMap->getWidth(),UranusMap->getHeight(),0,GL_RGBA,GL_FLOAT,UranusMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Uranus"] = textureUranus;

    //texture Neptune
    glGenTextures(1,&textureNeptune);
    glBindTexture(GL_TEXTURE_2D,textureNeptune);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,NeptuneMap->getWidth(),NeptuneMap->getHeight(),0,GL_RGBA,GL_FLOAT,NeptuneMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Neptune"] = textureNeptune;

    //texture Pluto
    glGenTextures(1,&texturePluto);
    glBindTexture(GL_TEXTURE_2D,texturePluto);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,PlutoMap->getWidth(),PlutoMap->getHeight(),0,GL_RGBA,GL_FLOAT,PlutoMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    textures["Pluto"] = texturePluto;



}

void RenderManager::createtextureSatellites() {

    std::unique_ptr<Image> MoonMap=loadImage("P:\\IMAC\\IMAC 2\\OPENGL\\PROJET_SpacIMAC\\asset\\Textures\\moonmap.jpg");


    GLuint textureMoon;

    //texture Moon
    glGenTextures(1,&textureMoon);
    glBindTexture(GL_TEXTURE_2D,textureMoon);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,MoonMap->getWidth(),MoonMap->getHeight(),0,GL_RGBA,GL_FLOAT,MoonMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    texturesSatellites["Moon"] = textureMoon;

    if(MoonMap == NULL){
        std::cerr << "Une des textures n'a pas pu etre chargée. \n" << std::endl;
        exit(0);
    }

}


void RenderManager::initWindowManager(int width, int height, const char* name) {
    windowManager = new SDLWindowManager (width,height,name);
}

void RenderManager::initRenderManager() {
    initWindowManager(1600,1200,"GLimac");
    initSphere();
    initPlane();
    createTexturesPlanets();
    createtextureSatellites();
   // initMatrix();
}

void RenderManager::initSphere() {
    MySphere = new Sphere(1,32,16);
}

void RenderManager::initPlane() {
    MyPlane = new Plane();
}


void RenderManager::initMatrix() {
/*
    glEnable(GL_DEPTH_TEST); //permet d'activer le test de profondeur du GPU. Sans cet appel de fonction, certains triangles non visible viendraient recouvrir des triangles situés devant.

    Matrix["ProjMatrix"] = glm::perspective(glm::radians(70.0f), 800.0f/600.0f, 0.1f, 100.0f); //param perspective(float fovy, float aspect, float znear, float far)
    Matrix["MVMatrix"]= glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    Matrix["NormalMatrix"] = glm::transpose(glm::inverse(uMVMatrix));

*/
}


int RenderManager::renderLoop(GLuint vao,AppManager* app) {
/*
    bool done = false;
    while(!done) {
        //Camera
        glm::mat4 ViewMatrix = Camera.getViewMatrix();

        // Event loop:
        SDL_Event e;
        while(windowManager->pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        //Ici on récupère les positions de la souris

        glm::ivec2 mousePos = windowManager->getMousePosition();
        if(windowManager->isMouseButtonPressed(SDL_BUTTON_RIGHT)) Camera.moveFront(0.01); //zoom avant
        else if(windowManager->isMouseButtonPressed(SDL_BUTTON_LEFT)) Camera.moveFront(-0.01); //zoom arrière


        //coordonnées recentrée
        int relPosX = mousePos.x - windowManager.getWindow_width()/2;
        int relPosY = mousePos.y - windowManager.getWindow_height()/2 ;

        std::cout << relPosX << std::endl;


        //rotation de la caméra au clavier
        if (windowManager->isKeyPressed(SDLK_z)){
            Camera.rotateUp();
        }
        if (windowManager->isKeyPressed(SDLK_s)){
            Camera.rotateDown();
        }
        if (windowManager->isKeyPressed(SDLK_q)){
            Camera.rotateRight();
        }
        if (windowManager->isKeyPressed(SDLK_d)){
            Camera.rotateLeft();
        }



        // Nettoyage de la fenêtre
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUniform1i(UniformVar["uTexture"], 0);
        glUniform1i(UniformVar["uTexture2"], 1);
        glBindVertexArray(vao);


        glm::mat4 Mrotate = glm::rotate(UniformVar["MVMatrix"],windowManager->getTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
        glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * ViewMatrix)); //Model View Projection
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(ViewMatrix * Mrotate));
        glUniformMatrix4fv(Matrix["uNormalMatrix"], 1, GL_FALSE, glm::value_ptr(NormalMatrix));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, getTexture("Sun")); // la texture SunTexture est bindée sur l'unité GL_TEXTURE0
        //glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, textureCloud); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

        glDrawArrays(GL_TRIANGLES, 0, MySphere->getVertexCount());


         //auto displayPlanet = [=] (Planete p) {
         Planete p = app->getPlanet("Earth");
         glActiveTexture(GL_TEXTURE0);
         glBindTexture(GL_TEXTURE_2D, getTexture(p.getName()));

         glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -15)); // Translation
         newMVMatrix = glm::rotate(newMVMatrix, windowManager->getTime(), glm::vec3(0.0,0.0,0.1)); // Translation * Rotation
         newMVMatrix = glm::translate(newMVMatrix, glm::vec3(0.0, 0.00005*p.getAphelion(),0.0)); // Translation * Rotation * Translation
         newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.00003*p.getDiametre(), 0.00003*p.getDiametre(), 0.00003*p.getDiametre())); // Translation * Rotation * Translation * Scale


         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * newMVMatrix));
         glUniformMatrix4fv(uMVMatrix, glm::value_ptr(uMVMatrix));
         glUniformMatrix4fv(Matrix["uNormalMatrix"], 1, GL_FALSE, glm::value_ptr(Matrix["NormalMatrix"]));

         glDrawArrays(GL_TRIANGLES, 0, MySphere->getVertexCount());

         glBindVertexArray(0);
         glActiveTexture(GL_TEXTURE0);
             //std::cout << "ok auto" << std::endl;
        // };

     //displayPlanet(app->getPlanet("Earth"));

        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);


        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Update the display
        windowManager->swapBuffers();
    }

    return EXIT_SUCCESS; */
}


void RenderManager::displayPlanet(Planete p) {
/*
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, getTexture(p.getName()));

    glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -15)); // Translation
    newMVMatrix = glm::rotate(newMVMatrix, windowManager->getTime(), glm::vec3(0.0,0.0,0.1)); // Translation * Rotation
    newMVMatrix = glm::translate(newMVMatrix, glm::vec3(0.0, 0.00005*p.getAphelion(),0.0)); // Translation * Rotation * Translation
    newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.00003*p.getDiametre(), 0.00003*p.getDiametre(), 0.00003*p.getDiametre())); // Translation * Rotation * Translation * Scale


    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(Matrix["ProjMatrix"] * newMVMatrix));
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(uMVMatrix));
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(Matrix["NormalMatrix"]));

    glDrawArrays(GL_TRIANGLES, 0, MySphere->getVertexCount());

    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);
    std::cout << "ok auto" << std::endl;*/
}
















