#pragma once
#include "Window.h"
class Renderer
{
private:
	Window* window;
	GLFWwindow* windowContext;
public:
	Renderer();
	void Update();
	~Renderer();
};

