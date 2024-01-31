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

    /*float vertices[]{
           -1.0f, -1.0f, 0.0f,
           -0.0f, -1.0f, 0.0f,
           -1.0f,  1.0f, 0.0f,
    };

    float vertices2[] = {
            1.0f, 1.0f, 0.0f,
            1.0f,  -1.0f, 0.0f,
            0.0f,  -1.0f, 0.0f,

    };*/
    Vertex vertices3[] = {
        Vertex{Vector3{0.5f, -0.5f, 0.0f}, Colour::red},
        Vertex{Vector3{-0.5f, -0.5f, 0.0}, Colour::green},
        Vertex{Vector3{0.0f,  0.5f, 0.0f}, Colour::blue}
    };

    Mesh mesh3{ vertices3, size(vertices3) };

    /*Mesh mesh1{vertices, size(vertices)};
    Mesh mesh2{vertices2, size(vertices2)};*/
  

    // ----- Compile the Vertex Shader on the GPU -------

    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};
    Shader orangeShader{"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};
    Shader yellowShader{"yellowFragmentShader.glsl", GL_FRAGMENT_SHADER};
    Shader rainbowShader{"rainbowFragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader rgbShader{ "rgbShader.glsl", GL_FRAGMENT_SHADER };


    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };
    Material rainbow{ vertexShader, rainbowShader };
    Material rgb{ vertexShader, rgbShader };

    /*Triangle a{&rgb, &mesh1};
    a.red = 1; a.green = 0; a.red = 0;

    Triangle b{&rgb, &mesh2};
    b.red = 0; b.green = 1; b.red = 0;*/

    Triangle c{ &rgb, &mesh3};



    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        window.Clear();

        /*a.Render();
        b.Render();*/
        c.Render();


        // present (send the current frame to the computer screen)
        window.Present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}