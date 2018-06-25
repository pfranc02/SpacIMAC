#ifndef TRACKBALL_CAMERA_H
#define TRACKBALL_CAMERA_H

#include <glimac/glm.hpp>

class TrackballCamera {
private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
public:
    TrackballCamera();
    void moveFront(float delta);
    void rotateLeft();
    void rotateUp();
    void rotateDown();
    void rotateRight();
    glm::mat4 getViewMatrix() const;
};

#endif //TRACKBALL_CAMERA_H
