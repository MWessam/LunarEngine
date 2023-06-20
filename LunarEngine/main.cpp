#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include <memory>

enum renderType 
{
	MESHRENDER,
	SPRITERENDER
};
int main()
{
	Renderer mainRenderer;
	mainRenderer.createCamera(90);
	mainRenderer.createWindow(1920, 1080, "Lunar Engine");
	mainRenderer.createInstance();
	std::vector<GameObject> gameObjs;
	// Instantiating objects
	for (int i = 0; i < 200; i++)
	{
		float random = rand() / (float)RAND_MAX * 2 - 1;
		GameObject gameObject;
		gameObject.getTransform()->scale(random);
		gameObject.getTransform()->setPosition({ random, random, 0.0f });
		gameObject.addToInstance(mainRenderer._instance);
		gameObjs.push_back(gameObject);
	}
	while (mainRenderer.clear())
	{
		mainRenderer.printFPS();
	}
}
