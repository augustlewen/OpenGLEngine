#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
#include "stb_image.h"
#include "Texture.h"


using namespace std;


void processInput(GLFWwindow*);

int main() {

    Window window{800, 600};


    Texture container{ "container.jpg", GL_TEXTURE0 };
    Texture wall{ "wall.jpg", GL_TEXTURE1};


    Vertex vertices[] = {
        // positions                            // colors           // texture coords
        Vertex{Vector3{0.5f,  0.5f, 0.0f},      Colour::red,        Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{0.5f, -0.5f, 0.0f},      Colour::green,      Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},     Colour::blue,       Vector2{0.0f, 0.0f}},   // bottom left

        Vertex{Vector3{-0.5f, 0.5f, 0.0f},     Colour::yellow,     Vector2{0.0f, 1.0f}},    // top left 
        Vertex{Vector3{0.5f,  0.5f, 0.0f},      Colour::red,        Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},     Colour::blue,       Vector2{0.0f, 0.0f}},   // bottom left
    };

    Mesh mesh{vertices, size(vertices)};



    // ----- Compile the Vertex Shader on the GPU -------

    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};

    Shader rainbowShader{"rainbowFragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader rgbShader{ "rgbShader.glsl", GL_FRAGMENT_SHADER };
    Shader textureShader{ "textureFragmentShader.glsl", GL_FRAGMENT_SHADER };


    Material rainbow{ vertexShader, rainbowShader };
    Material rgb{ vertexShader, rgbShader };
    Material textured{ vertexShader, textureShader };


    Triangle c{ &textured, &mesh, &container};
    Triangle d{ &textured, &mesh, &wall};

    c.offsetX = -0.5f;
    c.offsetY = -0.25f;

    d.offsetX = 0.5f;
    d.offsetY = 0.25f;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        window.Clear();

        /*float timeValue = glfwGetTime();
        float time = (sin(timeValue) / 2.0f);
        d.offsetY = time;
        d.offsetX = time;*/
        c.Render();
        d.Render();


        // present (send the current frame to the computer screen)
        window.Present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}