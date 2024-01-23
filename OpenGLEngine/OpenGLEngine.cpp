#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#if WIN32 || _WIN64
#include <Windows.h>
#endif

using namespace std;

void processInput(GLFWwindow*);

void error_callback(int error, const char* msg) {
    cerr << " [" << error << "] " << msg << endl;
}


int main() {

    glfwSetErrorCallback(error_callback);

    // Initialize GLFW
    if (!glfwInit()) { // Exit, if it failed
        std::cout << "Failed to init GLFW" << std::endl;
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //Request window from operating system
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Initiate GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);


    // Initialization ends here
    // =============================================================
    // Here we get to the good shit

    //While the User doesn't want to Quit (x Button, Alt F4)
    while (!glfwWindowShouldClose(window))
    {
        //process input (e.g. close window on Esc)
        glfwPollEvents();
        processInput(window);

        //render (paint the current frame of the game)
        glClearColor(0.2f, 0.5f, 0.75f, 0.2f);

        glClear(GL_COLOR_BUFFER_BIT);

        //present (send the current frame to the omputer screen)
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}