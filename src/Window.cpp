#include "ACGL/Window.hpp"

// Constructor that generates a Elements Buffer Object and links it to indices
Window::Window(const char *title, unsigned int width, unsigned int height, glm::vec3 camPosition) : title(title),
	width(width), height(height), camera(width, height, camPosition)
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
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;
	}
    else
    {
        std::cout << "window is not null\n";
    }
	// Introduce the window into the current context
    glfwMakeContextCurrent(window);
}

Window::~Window()
{
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

// Binds the EBO
GLFWwindow* Window::getWindow()
{
	return window;
}

int Window::getShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

void Window::getInputs()
{
	camera.Inputs(window);
}

void Window::uMatrix(Shader& shader, std::string uName)
{
	// Updates and exports the camera matrix to the Vertex Shader
	camera.Matrix(45.0f, 0.1f, 100.0f, shader, uName.data());
}

void Window::setBackgroundColor(glm::vec4 color)
{
	// Specify the color of the background
	GLCall(glClearColor(color.r, color.g, color.b, color.a), __FILE__, __LINE__);
}

void Window::bitClear(GLbitfield mask)
{
	glClear(mask);
}