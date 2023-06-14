#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Camera.h"
#include "Components/GameObject.h"
int main()
{
	Window mainwindow(4, 3, 3, 1920, 1080, GLFW_OPENGL_CORE_PROFILE, "Lunar Engine");
	Camera cam(5,5);
	Renderer mainRenderer(&mainwindow, &cam);
	GameObject go1;
	mainwindow.setColor({0.7f, 0.4f, 0.3f, 1.0f});
	mainRenderer.addGameObject(&go1);
	float x = 0.05f;
	while (mainRenderer.update()) 
	{
		go1.getTransform()->move(4 * sin(x), 4 * cos(x), 4 * sin(x));
	}
}
