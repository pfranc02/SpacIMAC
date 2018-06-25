
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
#include "project/AppManager.hpp"
#include "project/RenderManager.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(1600, 1200, "GLImac");
    AppManager *app = new AppManager();
    bool displaySun = true;
    app->initier_system();
    std::map<std::string, Planete> system = app->getSysteme_solaire();


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
    RenderManager *render = new RenderManager();
    render->initRenderManager();
    // Equation paramétrique en (r, phi, theta) de la sphère

    //Chargement des shaders
    FilePath applicationPath(argv[0]);
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

    TrackballCamera Camera;
   /* render->createTexturesPlanets();
    render->createtextureSatellites();*/

    //Puis on envois les données à la CG
    glBufferData(GL_ARRAY_BUFFER, render->getMySphere()->getVertexCount()*sizeof(ShapeVertex), render->getMySphere()->getDataPointer(), GL_STATIC_DRAW);
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
    int starPosition[2][400];
    for (int c =0; c <=1;c++){
        for(int d = 0; d <= 399; d++){
            starPosition[c][d] = rand()%200;
        }
    }

    //tableau positions étoiles
    int starScale[400];
        for(int e = 0; e <= 399; e++){
            starScale[e] = rand()%5;
        }


    //TrackballCamera Camera;

/*
    //Vecteurs contenant les axes de rotation et de translation des astres autour du soleil
    std::vector<glm::vec3> AxesRotation;
    std::vector<glm::vec3> AxesTranslation;

*/
    std::map<std::string, Planete>::iterator displayedPlanet = system.begin();
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
        if (windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) Camera.moveFront(0.01); //zoom avant
        else if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT)) Camera.moveFront(-0.01); //zoom arrière

        /*
        //coordonnées recentrée
        int relPosX = mousePos.x - windowManager.getWindow_width()/2;
        int relPosY = mousePos.y - windowManager.getWindow_height()/2 ;

        std::cout << relPosX << std::endl;
         */

        /***Contrôles***/
        //rotation de la caméra au clavier
        if (windowManager.isKeyPressed(SDLK_z)) {
            Camera.rotateUp();
        }
        if (windowManager.isKeyPressed(SDLK_s)) {
            Camera.rotateDown();
        }
        if (windowManager.isKeyPressed(SDLK_q)) {
            Camera.rotateRight();
        }
        if (windowManager.isKeyPressed(SDLK_d)) {
            Camera.rotateLeft();
        }

        //gestion vitesse
        if (windowManager.isKeyPressed(SDLK_f)) {
            app->getTime()->setValue(app->getTime()->getValue() + 500);
            if (app->getTime()->getSpeed() == 1)
                app->getTime()->setSpeed(500);
        }

        if (!windowManager.isKeyPressed(SDLK_f) && app->getTime()->getSpeed() == 500) {
            app->getTime()->setSpeed(1);
        }

        //afficher soleil
        if (windowManager.isKeyPressed(SDLK_c)) {
            displaySun =!displaySun;
        }

        if (windowManager.isKeyPressed(SDLK_v)) {
            if(displayedPlanet->second.getName() == "Venus"){
                displayedPlanet = system.begin();
            }else displayedPlanet++;
            std::cout << displayedPlanet->second.getName() << std::endl;
        }

        // Nettoyage de la fenêtre
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUniform1i(uTexture, 0);
        glUniform1i(uTexture2, 1);
        glBindVertexArray(vao);

        glActiveTexture(GL_TEXTURE0);
        if(!displaySun){
            Planete dp= displayedPlanet->second;
            glBindTexture(GL_TEXTURE_2D, render->getTexture(dp.getName()));
            dp.display_satellites();
            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -20));
            MVMatrix = glm::rotate(MVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue())/dp.getPeriode(), glm::vec3(0.0, 1.0,0.0)); // Translation * Rotation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.0002 * dp.scale_diametre(), 0.0002 * dp.scale_diametre(), 0.0002 * dp.scale_diametre())); // Translation * Rotation * Translation * Scale
            std::cout << (windowManager.getTime() * 50 + app->getTime()->getValue())/dp.getPeriode() << std::endl;

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix *MVMatrix)); //Model View Projection
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

        //glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, textureCloud); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

        glDrawArrays(GL_TRIANGLES, 0, render->getMySphere()->getVertexCount());


        // auto displayPlanet = [=] (Planete p) {
            if(dp.getName() != "Mercury" && dp.getName() != "Venus"){
                int satnbr =4;

                std::map<std::string,Satellite>sat = dp.getSatellites();
                //for (std::map<std::string,Satellite>::iterator it2 = sat.begin(); it2 != sat.end(); it2++) {
                    Satellite s = sat.begin()->second;
                    std::cout << s.getName() << std::endl;
                    /*
                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, render->getTextureSatellites("Moon"));
                    glm::mat4  newMVMatrix = glm::rotate(newMVMatrix,windowManager.getTime(), glm::vec3(0, 10, 0)); // Translation * Rotation
                    newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, -1, -20)); // Translation
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue())/1000, glm::vec3(0.0, 1, 1)); // Translation * Rotation
                    newMVMatrix = glm::translate(newMVMatrix, glm::vec3(0.0,satnbr s.getSm_axis()/50000, 0.0)); // Translation * Rotation * Translation

                    newMVMatrix = glm::scale(newMVMatrix, glm::vec3(s.getDiametre()*0.0001 ,s.getDiametre()*0.0001,s.getDiametre()*0.0001)); // Translation * Rotation * Translation * Scale


                    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * newMVMatrix));
                    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
                    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

                    glDrawArrays(GL_TRIANGLES, 0, render->getMySphere()->getVertexCount());
                satnbr++;
                    */
           // }
        }
    } else {
            glBindTexture(GL_TEXTURE_2D, render->getTexture("Sun"));

            MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,2.5, -20));
            MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0.1, (windowManager.getTime() * 50 + app->getTime()->getValue())/(app->getSoleil()->getRot_propre()), 10)); // Translation * Rotation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.0000006 * app->getSoleil()->getDiametre(), 0.0000006 * app->getSoleil()->getDiametre(), 0.0000006 * app->getSoleil()->getDiametre())); // Translation * Rotation * Translation * Scale

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix *MVMatrix)); //Model View Projection
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            //glActiveTexture(GL_TEXTURE1);
            // glBindTexture(GL_TEXTURE_2D, textureCloud); // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1

            glDrawArrays(GL_TRIANGLES, 0, render->getMySphere()->getVertexCount());


            // auto displayPlanet = [=] (Planete p) {
            //int i = 1;
            for (std::map<std::string, Planete>::iterator it = system.begin(); it != system.end(); ++it) {
                Planete p = it->second;
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, render->getTexture(p.getName()));


                glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,-app->scale_distance(p)/2 +3, -25)); // Translation
                if(p.getName() =="Pluto"){
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue()) / (p.getPeriode()), glm::vec3(0.4, 1, 1)); // Translation * Rotation
                }else{
                    newMVMatrix = glm::rotate(newMVMatrix, (windowManager.getTime() * 50 + app->getTime()->getValue()) / (p.getPeriode()), glm::vec3(0.0, 1, 1)); // Translation * Rotation
                }
                newMVMatrix = glm::translate(newMVMatrix, glm::vec3(0, app->scale_distance(p), 0.0)); // Translation * Rotation * Translation
                newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.00002 * p.scale_diametre(), 0.00002 * p.scale_diametre(), 0.00002 * p.scale_diametre())); // Translation * Rotation * Translation * Scale*/


                glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * newMVMatrix));
                glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
                glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

                glDrawArrays(GL_TRIANGLES, 0, render->getMySphere()->getVertexCount());
            }
        }

        for (int i = 0; i <=400; i++) {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, render->getTextureSatellites("Moon"));
            glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(starPosition[0][i]-100,starPosition[1][i]-100,-100)); // Translation
            newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.03*starScale[i],0.03*starScale[i],0.03*starScale[i])); // Translation * Rotation * Translation * Scale*/


            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * newMVMatrix));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            glDrawArrays(GL_TRIANGLES, 0, render->getMySphere()->getVertexCount());
            //i++;
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
