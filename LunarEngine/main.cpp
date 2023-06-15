#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Camera.h"
#include "Components/GameObject.h"
#include "Components/GraphicsRenderer.h"

enum renderType 
{
	MESHRENDER,
	SPRITERENDER
};
int main()
{
	Window mainwindow(4, 4, 6, 1920, 1080, GLFW_OPENGL_CORE_PROFILE, "Lunar Engine");
	Camera cam(90.0f);
	Renderer mainRenderer(&mainwindow, &cam);
	std::vector<GameObject*> gameObjs;
	mainwindow.setColor({1.0f, 0.4f, 0.3f, 1.0f});
	int step = 0;
	float x = 0.005f;
	for (int i = 0; i < 2; i++) 
	{
		GameObject* go = new GameObject();
		go->getGraphicsRenderer()->setTexture("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/Textures/flappyBird.png");
		mainRenderer.addGameObject(go);
		gameObjs.push_back(go);
	}
	gameObjs[0]->getTransform()->setPosition({ -0.9f, -0.6f , 0.0f });
	gameObjs[1]->getTransform()->setPosition({ 0.7f, 0.6f , 0.0f });
	while (mainRenderer.clear())
	{
		gameObjs[0]->getTransform()->lerpTowards(gameObjs[1]->getTransform(), mainRenderer.DeltaTime, 1.0f);
	}
}
