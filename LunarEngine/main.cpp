#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"


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
	double xpos = 0.0f;
	double ypos = 0.0f;
	double pixelX, pixelY;
	// Instantiating objects
	while (mainRenderer.clear())
	{
		glfwGetCursorPos(mainRenderer.getWindow(), &xpos, &ypos);
		pixelX = ( xpos - ( 1920 ) ) / 1920;
		pixelY = 1 - (2.0 * ypos) / 1080;
		if (glfwGetMouseButton(mainRenderer.getWindow(), GLFW_MOUSE_BUTTON_1))
		{
			GameObject* gameObject = new GameObject();
			gameObject->addToInstance(mainRenderer._instance);
			gameObject->getTransform()->setPosition({ pixelX, pixelY, 0.0f });
		}
		mainRenderer.printFPS();
	}
	
}
