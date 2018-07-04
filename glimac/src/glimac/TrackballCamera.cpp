#include <glimac/TrackballCamera.hpp>
#include <iostream>
#include "../../include/glimac/TrackballCamera.hpp"

TrackballCamera::TrackballCamera() {
    m_fDistance = 17;
    m_fAngleX = m_fAngleY = 0;
    m_Translate_X=0;
}

void TrackballCamera::moveFront(float delta)
{
    m_fDistance += delta;

}

void TrackballCamera::rotateLeft()
{
    m_fAngleX += -2;

}
void TrackballCamera::rotateRight()
{
    m_fAngleX += 2;
    std::cout <<  "mf_angle:" << m_fAngleX << std::endl;
}

void TrackballCamera::rotateUp()
{
    m_fAngleY += -2;
    std::cout <<  "mf_angle:" << m_fAngleY << std::endl;
}

void TrackballCamera::rotateDown() {
    m_fAngleY += 2;
    std::cout <<  "mf_angle:" << m_fAngleY << std::endl;
}

void TrackballCamera::zoomIn() {
    m_fDistance --;
    std::cout << m_fDistance << std::endl;
}

void TrackballCamera::zoomOut() {
    m_fDistance ++;
    std::cout << m_fDistance << std::endl;
}

void TrackballCamera::moveLeft() {
    m_Translate_X= m_Translate_X-0.2;
}
void TrackballCamera::moveRight() {
    m_Translate_X= m_Translate_X+0.2;
}

void TrackballCamera::moveUp() {
    m_Translate_Y= m_Translate_Y+0.2;
}
void TrackballCamera::moveDown() {
    m_Translate_Y= m_Translate_Y-0.2;
}

glm::mat4 TrackballCamera::getViewMatrix() const
{
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.f),glm::vec3( m_Translate_X,m_Translate_Y, -m_fDistance));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(1,0,0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(0,1,0));
    return viewMatrix;
}


