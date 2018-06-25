#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include "glm.hpp"
#include <math.h>

#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/glm.hpp>
#include <glimac/Geometry.hpp>
#include <cstddef>
#include <vector>


namespace glimac {

struct ShapeVertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;

	ShapeVertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 texpos)
		: position(pos), normal(normal), texCoords(texpos) {}
	ShapeVertex(){}
};
// 3D Vertex structure
	struct Vertex3D {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoords;
	};
// Returns the norm of a vector
	float norm(glm::vec3 V);
// Return the vector normalize
	glm::vec3 normalize(glm::vec3 V);
// Returns the VBO, IBO and VAO of an object made with Vertex3D
	GLuint VBO(GLsizeiptr size, const GLvoid* data);
	GLuint IBO(GLsizeiptr size, const GLvoid* data);
	GLuint VAO(GLuint* ibo, GLuint* vbo);

	float floatDivision(float a, float b);
}
