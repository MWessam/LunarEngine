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
	GameObject go1;
	GameObject go2;
	mainwindow.setColor({1.0f, 0.4f, 0.3f, 1.0f});
	mainRenderer.addGameObject(&go1);
	mainRenderer.addGameObject(&go2);
	go1.getGraphicsRenderer()->setTexture("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/Textures/pipe.png");
	go2.getGraphicsRenderer()->setTexture("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/Textures/flappyBird.png");

	go1.getGraphicsRenderer()->setColor({ 0.7f,0.5f,0.3f,1.0f });
	go2.getGraphicsRenderer()->setColor({ 0.1f,0.3f,0.9f,1.0f });

	float x = 0.05f;
	while (mainRenderer.clear()) 
	{
		go1.getGraphicsRenderer()->getTransform()->scale(sin(x));
		go2.getGraphicsRenderer()->getTransform()->scale(cos(x) / 2);
		x += 0.001f;
	}
}
