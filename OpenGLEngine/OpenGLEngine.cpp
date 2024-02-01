#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
#include "stb_image.h"

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

    int width, height, nrChannels;
    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

    unsigned int textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

 

    Vertex vertices4[] = {
        // positions                            // colors           // texture coords
        Vertex{Vector3{0.5f,  0.5f, 0.0f},      Colour::red,        Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{0.5f, -0.5f, 0.0f},      Colour::green,      Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},     Colour::blue,       Vector2{0.0f, 0.0f}},   // bottom left

        Vertex{Vector3{-0.5f, 0.5f, 0.0f},     Colour::yellow,     Vector2{0.0f, 1.0f}},    // top left 
        Vertex{Vector3{0.5f,  0.5f, 0.0f},      Colour::red,        Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},     Colour::blue,       Vector2{0.0f, 0.0f}},   // bottom left
    };

    Mesh mesh4{vertices4, size(vertices4)};



    // ----- Compile the Vertex Shader on the GPU -------

    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};

    Shader rainbowShader{"rainbowFragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader rgbShader{ "rgbShader.glsl", GL_FRAGMENT_SHADER };
    Shader textureShader{ "textureFragmentShader.glsl", GL_FRAGMENT_SHADER };


    Material rainbow{ vertexShader, rainbowShader };
    Material rgb{ vertexShader, rgbShader };
    Material textured{ vertexShader, textureShader };


    Triangle d{ &textured, &mesh4};
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        window.Clear();
        float timeValue = glfwGetTime();
        float time = (sin(timeValue) / 2.0f);
        d.offsetY = time;
        d.offsetX = time;

        d.Render();


        // present (send the current frame to the computer screen)
        window.Present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}