#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
class Window
{
private:
	GLFWwindow* _window;
	unsigned int _antiAliasing;
	unsigned int _minorVersion;
	unsigned int _majorVersion;
	unsigned int _width;
	unsigned int _height;
	GLint _glProfile;
	std::string _title;
	int initializeGlad() const;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput();
public:
	Window(unsigned int antiAliasing, unsigned int majorVersion, unsigned int minorVersion, unsigned int width, unsigned int height, GLint glProfile, const std::string title);
	~Window();
	GLFWwindow* getWindow() const;
	void assignAsCurrentContext() const;
	void changeViewport(GLint x, GLint y, GLsizei width, GLsizei height) const;
	void update();
	
};

