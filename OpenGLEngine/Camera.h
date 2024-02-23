#pragma once
#include "Object.h"
#include "Window.h"

class Camera : public Object
{
    Window* window;
public:
    float fieldOfViewDegrees;
    
    Camera(Window* window) : window{window}, fieldOfViewDegrees{45}{}

    // virtual void Update()
    // {
    //     const float cameraSpeed = 0.05f;
    //     if(window->getKeyDown(KeyCode::W))
    //         cameraPos += cameraSpeed * cameraFront;
    //     else if(window->getKeyDown(KeyCode::S))
    //         cameraPos -= cameraSpeed * cameraFront;
    //     else if(window->getKeyDown(KeyCode::A))
    //         cameraPos -= glm::normalize(glm::cross(cameraFront)) * cameraSpeed;
    //     else if(window->getKeyDown(KeyCode::D))
    //         cameraPos += glm::normalize(glm::cross(cameraFront)) * cameraSpeed;
    // }
    
    float getAspectRatio()
    {
        return window->getWidth() / window->getHeight();
    }

    float fieldOfViewRadians()
    {
        double pi = 2*acos(0.0);
        return fieldOfViewDegrees / 360 * 2 * pi;

    }
    
    Matrix4x4 projectionMatrix()
    {
        return Matrix4x4::Perspective(fieldOfViewRadians(), getAspectRatio(), 0.1f, 100);
    }
    Matrix4x4 viewMatrix()
    {
        return calculateModelMatrix().Inverse();
    }
};
