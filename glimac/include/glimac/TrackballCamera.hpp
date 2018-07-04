#ifndef TRACKBALL_CAMERA_H
#define TRACKBALL_CAMERA_H

#include <glimac/glm.hpp>

class TrackballCamera {
private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
    float m_Translate_X;
    float m_Translate_Y;

public:
    TrackballCamera();
    void moveFront(float delta);
    void rotateLeft();
    void rotateUp();
    void rotateDown();
    void rotateRight();
    void zoomIn();
    void zoomOut();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    glm::mat4 getViewMatrix() const;
};

#endif //TRACKBALL_CAMERA_H
