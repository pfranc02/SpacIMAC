#include <glimac/TrackballCamera.hpp>
#include <iostream>

TrackballCamera::TrackballCamera() {
    m_fDistance = 17;
    m_fAngleX = m_fAngleY = 0;
}

void TrackballCamera::moveFront(float delta)
{
    m_fDistance += delta;

}

void TrackballCamera::rotateLeft()
{
    m_fAngleX += -10;
}
void TrackballCamera::rotateRight()
{
    m_fAngleX += 10;
}

void TrackballCamera::rotateUp()
{
    m_fAngleY += -10;
    std::cout <<  "mf_angle:" << m_fAngleY << std::endl;
}

void TrackballCamera::rotateDown() {
    m_fAngleY += 10;
    std::cout <<  "mf_angle:" << m_fAngleY << std::endl;
}

glm::mat4 TrackballCamera::getViewMatrix() const
{
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.f),glm::vec3(0, 0, -m_fDistance));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(1,0,0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(0,1,0));
    return viewMatrix;
}

