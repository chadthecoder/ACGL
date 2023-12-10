#include "ACGL/GLFW.hpp"

// Constructor that generates a Elements Buffer Object and links it to indices
GLFW::GLFW(const char *title, unsigned int width, unsigned int height) : title(title), width(width), height(height)
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;
	}
    else
    {
        std::cout << "window null\n";
    }
	// Introduce the window into the current context
	//glfwMakeContextCurrent(window);
}

// Binds the EBO
GLFWwindow* GLFW::getWindow()
{
	return window;
}

int GLFW::getShouldClose()
{
    return glfwWindowShouldClose(window);
}

void GLFW::makeContextCurrent()
{
    glfwMakeContextCurrent(window);
}