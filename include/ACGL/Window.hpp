#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ACGL/Camera.hpp>
#include <ACGL/Shader.hpp>

#include <iostream>

class Window
{
public:
	GLFWwindow* window;

	Camera camera;

    //const unsigned int width, height;
	int width, height;

    const char *title;
    // ID reference of Elements Buffer Object
	//GLuint ID;
	// Constructor that generates a Elements Buffer Object and links it to indices
	Window(const char *title, unsigned int width, unsigned int height, glm::vec3 camPosition);
	~Window();

    GLFWwindow* getWindow();
    int getShouldClose();
	void swapBuffers();
	void getInputs();
	void uMatrix(Shader& shader, std::string uName);
	void setBackgroundColor(glm::vec4 color);
    //void makeContextCurrent();
    
	// Binds the EBO
	//void Bind();
	// Unbinds the EBO
	//void Unbind();
	// Deletes the EBO
	//void Delete();
};

#endif