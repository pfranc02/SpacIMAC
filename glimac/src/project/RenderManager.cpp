#include "project/RenderManager.hpp"
#include "../../include/glimac/TrackballCamera.hpp"
#include "../../include/project/RenderManager.hpp"
#include "../../include/glimac/Program.hpp"
#include "../../include/glimac/Image.hpp"

#define GLEW_STATIC
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

    //createTexture(textureSun,SunMap);

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
    if(MoonMap == NULL){
        std::cerr << "Une des textures n'a pas pu etre chargée. \n" << std::endl;
        exit(0);
    }

    GLuint textureMoon;

    //texture Moon
    glGenTextures(1,&textureMoon);
    glBindTexture(GL_TEXTURE_2D,textureMoon);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,MoonMap->getWidth(),MoonMap->getHeight(),0,GL_RGBA,GL_FLOAT,MoonMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    texturesSatellites["Moon"] = textureMoon;

}



void RenderManager::initRenderManager() {
    initSphere();
    createTexturesPlanets();
    createtextureSatellites();
}

void RenderManager::initSphere() {
    MySphere = new Sphere(1,32,16);
}



int RenderManager::renderLoop(char* arg) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(1600, 1200, "GLImac");
    app = new AppManager();
    displaySun = true;
    app->initier_system();
    system = app->getSysteme_solaire();
    std::cout<< system.size()<< std::endl;


    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /**********************************/
    /********* INITIALISATION *********/
    /**********************************/

    //création de moteur de rendu
    initRenderManager();
    // Equation paramétrique en (r, phi, theta) de la sphère
    Plane *myPlane = new Plane();

    //Chargement des shaders
    FilePath applicationPath(arg);
    Program program = loadProgram(
            applicationPath.dirPath() + "shaders/3D.vs.glsl",
            applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl"
    );
    program.use();

    //Obtention de l'id de la variable uniforme
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
    GLint uTexture2 = glGetUniformLocation(program.getGLId(), "uTexture2");

    glEnable(GL_DEPTH_TEST); //permet d'activer le test de profondeur du GPU. Sans cet appel de fonction, certains triangles non visible viendraient recouvrir des triangles situés devant.

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.0f), 800.0f/600.0f, 0.1f, 100.0f); //param perspective(float fovy, float aspect, float znear, float far)
    glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glm::mat4 Mrotate = glm::rotate(MVMatrix,windowManager.getTime(), glm::vec3(0.0f, 1.0f, 0.0f));


    //Création d'un VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    //Bindind du vbo sur la cible
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    /* render->createTexturesPlanets();
     render->createtextureSatellites();*/

    //Puis on envois les données à la CG
    glBufferData(GL_ARRAY_BUFFER, getMySphere()->getVertexCount()*sizeof(ShapeVertex), getMySphere()->getDataPointer(), GL_STATIC_DRAW);
    //Débindind du vbo de la cible pour éviter de le remodifier
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Création du VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //Binding du vao (un seul à la fois)
    glBindVertexArray(vao);

    //Dire à OpenGL qu'on utilise le VAO
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORDS = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

    //Indiquer à OpenGL où trouver les sommets
    //Bindind du vbo sur la cible
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //Spécification du format de l'attribut de sommet position
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));
    //Débindind du vbo de la cible pour éviter de le remodifier
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Débindind du vao de la cible pour éviter de le remodifier
    glBindVertexArray(0);

    //tableau Positions étoiles
    int starPosition[3][4000];
    for (int c =0; c <=1;c++){
        for(int d = 0; d <= 3999; d++){
            starPosition[c][d] = rand()%500;
        }
    }
    for(int e =0; e<=3999; e++){
        starPosition[2][e] = rand()%100;
    }

    //tableau  échelles étoiles
    int starScale[4000];
    for(int e = 0; e <= 3999; e++){
        starScale[e] = rand()%5;
    }



   displayedPlanet = system.begin();
    /**********************************/
    /******* BOUCLE D'AFFICHAGE *******/
    /**********************************/


    // Application loop:

    bool done = false;
    while(!done) {

        //Camera
        glm::mat4 ViewMatrix = Camera.getViewMatrix();

        // Event loop:
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        //Ici on récupère les positions de la souris

        glm::ivec2 mousePos = windowManager.getMousePosition();


        /***Contrôles***/
        //rotation de la caméra au clavier

        Control(&windowManager);
        // Nettoyage de la fenêtre
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUniform1i(uTexture, 0);
        glUniform1i(uTexture2, 1);
        glBindVertexArray(vao);
        glActiveTexture(GL_TEXTURE0);
        double time = windowManager.getTime();

        /***AFFICHER D'UNE SEULE PLANETE***/
        if(!displaySun){
            Planete dp= displayedPlanet->second;
            glBindTexture(GL_TEXTURE_2D, getTexture(dp.getName()));

            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0));
            MVMatrix = glm::rotate(MVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue())/dp.getPeriode(), glm::vec3(0.0, 1.0,0.0)); // Translation * Rotation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.0002 * dp.scale_diametre(), 0.0002 * dp.scale_diametre(), 0.0002 * dp.scale_diametre())); // Translation * Rotation * Translation * Scale

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*ViewMatrix *MVMatrix)); //Model View Projection
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());


            // auto displayPlanet = [=] (Planete p) {

            /***AFFICHER LES SATELLITES DE LA PLANETE***/
            if(dp.getName() != "Mercury" && dp.getName() != "Venus"){ int satnbr =6;

                std::map<std::string,Satellite>sat = dp.getSatellites();
                for (std::map<std::string,Satellite>::iterator it2 = sat.begin(); it2 != sat.end(); it2++) {
                    Satellite s = it2->second;

                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, getTextureSatellites("Moon"));

                    glm::mat4  newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,0,0)); // Translation
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue())/(s.getRot_propre()*20), glm::vec3(0, 10, 0)); // Translation * Rotation
                    newMVMatrix = glm::translate(newMVMatrix, glm::vec3(-s.getSm_axis()/75000,0,0)); // Translation * Rotation * Translation
                    newMVMatrix = glm::scale(newMVMatrix, glm::vec3(s.getDiametre()*0.0001 ,s.getDiametre()*0.0001,s.getDiametre()*0.0001)); // Translation * Rotation * Translation * Scale



                    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix *ViewMatrix* newMVMatrix));
                    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
                    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

                    glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());
                }
            }
        } else {


            /***AFFICHER LE SOLEIL***/


            glBindTexture(GL_TEXTURE_2D, getTexture("Sun"));

            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,0,0));
            MVMatrix = glm::rotate(MVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue())/(app->getSoleil()->getRot_propre()), glm::vec3(0.0, 1.0,0.0)); // Translation * Rotation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.0000006 * app->getSoleil()->getDiametre(), 0.0000006 * app->getSoleil()->getDiametre(), 0.0000006 * app->getSoleil()->getDiametre())); // Translation * Rotation * Translation * Scale

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*ViewMatrix *MVMatrix)); //Model View Projection
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            //glActiveTexture(GL_TEXTURE1);
            // glBindTexture(GL_TEXTURE_2D, textureCloud); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

            glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());


            // auto displayPlanet = [=] (Planete p) {
            //int i = 1;

            /***AFFICHER LES PLANETES***/
            for (std::map<std::string, Planete>::iterator it = system.begin(); it != system.end(); ++it) {
                Planete p = it->second;
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, getTexture(p.getName()));

                // Translation * Rotation
                glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,-app->scale_distance(p)/2,-app->scale_distance(p)/2)); // Translation
                glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue()) / (p.getRot_propre()), glm::vec3(0, 10, 0));
                if(p.getName() =="Pluto"){
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue()) / (p.getPeriode()), glm::vec3(0.4, 1, 1)); // Translation * Rotation
                }else{
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue()) / (p.getPeriode()), glm::vec3(0.0, 1, 1)); // Translation * Rotation
                }

                newMVMatrix = glm::translate(newMVMatrix, glm::vec3(0, app->scale_distance(p), 0.0)); // Translation * Rotation * Translation
                newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.00002 * p.scale_diametre(), 0.00002 * p.scale_diametre(), 0.00002 * p.scale_diametre())); // Translation * Rotation * Translation * Scale*/


                glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*ViewMatrix * newMVMatrix));
                glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
                glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

                glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());
            }

            /***AFFICHER LES Asteroids***/
            for (int i = 0; i <=4000; i++) {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, getTextureSatellites("Moon"));
                glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(app->scale_distance(system["Mars"])+starPosition[0][i]/80,0,app->scale_distance(system["Mars"])+starPosition[0][i]/80)); // Translation
                newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.00002  * system["mars"].scale_diametre(),0.0002 * system["mars"].scale_diametre(),0.0002 * system["mars"].scale_diametre())); // Translation * Rotation * Translation * Scale

                glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*ViewMatrix* newMVMatrix));
                glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
                glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

                glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());
            }
        }

        /***AFFICHER LES ETOILES***/
        for (int i = 0; i <=4000; i++) {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, getTextureSatellites("Moon"));
            glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(starPosition[0][i]-250,starPosition[1][i]-250,starPosition[2][i]-50)); // Translation
            newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.02*starScale[i],0.02*starScale[i],0.02*starScale[i])); // Translation * Rotation * Translation * Scale*/

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*ViewMatrix* newMVMatrix));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            glDrawArrays(GL_TRIANGLES, 0, getMySphere()->getVertexCount());
        }



        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE0);
        //uMVPMatrix, UMVMatrix, ProjMatrix

        // };

        //displayPlanet(app->getPlanet("Earth"));

        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);


        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}


void RenderManager::Control(glimac::SDLWindowManager* windowManager) {
    if (windowManager->isKeyPressed(SDLK_w)){ //appuyer sur z
        Camera.rotateUp();
    }
    if (windowManager->isKeyPressed(SDLK_s)){ //appuyer sur sur S
        Camera.rotateDown();
    }
    if (windowManager->isKeyPressed(SDLK_a)){ //appuyer sur sur Q
        Camera.rotateRight();
    }
    if (windowManager->isKeyPressed(SDLK_d)) { //appuyer sur sur D
        Camera.rotateLeft();
    }
    if (windowManager->isKeyPressed(SDLK_i)) {
        Camera.zoomIn();
    }
    if (windowManager->isKeyPressed(SDLK_o)) {
        Camera.zoomOut();
    }
    if (windowManager->isKeyPressed(SDLK_LEFT)) {
        Camera.moveRight();
    }
    if (windowManager->isKeyPressed(SDLK_RIGHT)) {
        Camera.moveLeft();
    }
    if (windowManager->isKeyPressed(SDLK_UP)) {
        Camera.moveUp();
    }
    if (windowManager->isKeyPressed(SDLK_DOWN)) {
        Camera.moveDown();
    }


    //gestion vitesse
    if (windowManager->isKeyPressed(SDLK_f)) {
        //tant qu'on appuie
        app->getTime()->setValue(app->getTime()->getValue() + 1000);// chaque tour on augmente le temps écoulé de 500 ai lieu de 1
        if (app->getTime()->getSpeed() == 1) // si la vitesse est à 1 elle passe à 500 sinon elle reste à 500
            app->getTime()->setSpeed(1000);
    }

    if (!windowManager->isKeyPressed(SDLK_f) && app->getTime()->getSpeed() == 1000) {
        app->getTime()->setSpeed(1);
    }

    //afficher soleil
    if (windowManager->isKeyPressed(SDLK_c)) {
        displaySun =!displaySun;
    }

    if (windowManager->isKeyPressed(SDLK_v)) {
        if(displayedPlanet->second.getName() == "Venus"){
            displayedPlanet = system.begin();
        }else displayedPlanet++;
        std::cout << displayedPlanet->second.getName() << std::endl;
    }

}

/*
void RenderManager::createTexture(GLuint texture, std::unique_ptr<Image>map) {
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);   //Binding de la texture
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,map->getWidth(),map->getHeight(),0,GL_RGBA,GL_FLOAT,map->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    texturesSatellites["Moon"] = texture;
}
*/