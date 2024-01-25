#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"


using namespace std;


void processInput(GLFWwindow*);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void error_callback(int error, const char* msg) {
    cerr << " [" << error << "] " << msg << endl;
}



int main() {

    Window window{800, 600};

    float vertices[]{
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, 0.5f, 0.0f
    };

    float vertices2[] = {
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f
    };

    Mesh mesh1{vertices, size(vertices)};
    Mesh mesh2{vertices2, size(vertices2)};
  

    // ----- Compile the Vertex Shader on the GPU -------

    Shader vertexShader{"#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0", GL_VERTEX_SHADER};

    Shader orangeShader{ "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0", GL_FRAGMENT_SHADER};

    Shader yellowShader{ "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "} \0", GL_FRAGMENT_SHADER };


    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };

    Triangle a{&orange, &mesh1};
    Triangle b{&orange, &mesh2};


    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        window.Clear();

        a.Render();
        b.Render();

        // present (send the current frame to the computer screen)
        window.Present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}