#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>

using namespace glm;

int main(){

    if(!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // open a window and create it's OpenGL context
    window = glfwCreateWindow(1024, 768, "Create Window", NULL, NULL);
    if(window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Initialize GLEW

    if(glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW.\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // exit on pressing escape key
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do{
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // will draw here something later

        // swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // check if the esc key is pressed
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    // Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
