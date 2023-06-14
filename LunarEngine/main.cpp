#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Camera.h"
#include "Components/GameObject.h"
#include "Components/GraphicsRenderer.h"
int main()
{
	Window mainwindow(4, 3, 3, 1920, 1080, GLFW_OPENGL_CORE_PROFILE, "Lunar Engine");
	Camera cam(50,50);
	Renderer mainRenderer(&mainwindow, &cam);
	std::vector<GameObject> gameObjs;
	mainwindow.setColor({1.0f, 0.4f, 0.3f, 1.0f});
	int step = 0;
	float x = 0.005f;
	while (mainRenderer.clear()) 
	{

	}
}
void benchMark(GameObject& gameObject, float x) 
{
	gameObject.getGraphicsRenderer()->getTransform()->scale(sin(x));
}
