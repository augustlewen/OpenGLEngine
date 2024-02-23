#include <complex>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "GameObject.h"
#include "stb_image.h"
#include "Texture.h"
#include <vector>

using namespace std;

void processInput(GLFWwindow*);

int main() {

    Window window{ 800,600 }; // GLFW, GLAD, glViewport

    Texture container{ "container.jpg", GL_TEXTURE0 };
    Texture wall{ "wall.jpg", GL_TEXTURE1 };
    Texture face{ "awesomeface.png", GL_TEXTURE0 };

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };
    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader textureShader{ "textureFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material textured{ vertexShader, textureShader };

    GameObject cube{ &textured, Mesh::createCube(), &wall };


    Vector3 cubePositions[] = {
        Vector3(1.3f, -2.0f, -0.1f),
        Vector3(0.8f, -0.1f, -0.5f),
        Vector3(-0.2f, -0.5f, -0.8f),
        Vector3(-1.3f, 0.5f, 0.2f),
        Vector3(-1.8f, -2.0f, 1.5f),
        Vector3(2.3f, 2.0f, -0.5f),
    };


    vector<GameObject*> gameObjects{};
    for (size_t i = 0; i < size(cubePositions); i++)
    {
      GameObject* newCube = new GameObject{ &textured, Mesh::createCube(), &wall};
      newCube->rotation.z = i * 0.1f;
      newCube->rotation.x = i * 0.1f + 0.5f;
      newCube->position = cubePositions[i];
      gameObjects.push_back(newCube);
    }

    Camera camera{&window};

    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose()) // window -> window.window
    {
        window.processInput();

        window.clear();

        camera.position.z = (sin(glfwGetTime())+2) * 3;

        for (size_t i = 0; i < size(cubePositions); i++)
        {
            gameObjects[i]->render(&camera);
            gameObjects[i]->rotation.x = glfwGetTime();
            gameObjects[i]->rotation.y = glfwGetTime() * 0.4f;

        }

        window.present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}