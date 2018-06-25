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
    //SDLWindowManager windowManager(1200, 900, "GLImac");

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


    AppManager *app = new AppManager();
    app->initier_system();
    //création de moteur de rendu
    RenderManager *render = new RenderManager();

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(
            applicationPath.dirPath() + "shaders/3D.vs.glsl",
            applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl");
    program.use();

    render->setUMVPMatrix(glGetUniformLocation(program.getGLId(), "uMVPMatrix"));
    render->setUMVMatrix(glGetUniformLocation(program.getGLId(), "uMVMatrix"));
    render->setUTexture(glGetUniformLocation(program.getGLId(), "uTexture"));
    render->setUTexture2(glGetUniformLocation(program.getGLId(), "uTexture2"));


    render->initRenderManager();

    //glEnable(GL_DEPTH_TEST); //permet d'activer le test de profondeur du GPU. Sans cet appel de fonction, certains triangles non visible viendraient recouvrir des triangles situés devant.

    //Création d'un VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    //Bindind du vbo sur la cible
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    render->createTexturesPlanets();

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


    /**********************************/
    /******* BOUCLE D'AFFICHAGE *******/
    /**********************************/

    render->renderLoop(vao,app);
}
/*
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, render->getTexture("Earth"));

for (int i = 0; i < AxesRotation.size(); ++i)
{
    glm::mat4 newMVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5)); // Translation
    newMVMatrix = glm::rotate(newMVMatrix, windowManager.getTime(), AxesRotation[i]); // Translation * Rotation
    newMVMatrix = glm::translate(newMVMatrix, AxesTranslation[i]); // Translation * Rotation * Translation
    newMVMatrix = glm::scale(newMVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale

    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * newMVMatrix));
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    glDrawArrays(GL_TRIANGLES, 0, MySphere.getVertexCount());
}

*/