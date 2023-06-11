#include <iostream>
#include"Window.h"
#include"Renderer.h"

int main()
{
	Window mainwindow(4, 4, 6, 800, 600, GLFW_OPENGL_CORE_PROFILE, "Lunar Engine");
	Renderer mainRenderer(&mainwindow);
	while (mainRenderer.Update()) 
	{

	}
}
