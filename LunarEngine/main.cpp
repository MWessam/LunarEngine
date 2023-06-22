#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "PhysicsEngine.h"
#include "Components/RigidBody2DComponent.h"
#include <thread>
enum renderType 
{
	MESHRENDER,
	SPRITERENDER
};
int main()
{
	Renderer mainRenderer;
	mainRenderer.createOrthoCamera(20.0f, 20.0f);
	//mainRenderer.createPerspectiveCamera(90.0f);
	mainRenderer.createWindow(1920, 1080, "Lunar Engine");
	mainRenderer.createInstance();
	double xpos = 0.0f;
	double ypos = 0.0f;
	double pixelX, pixelY;
	PhysicsEngine physics;
	// Instantiating objects
	while (mainRenderer.clear())
	{
		glfwGetCursorPos(mainRenderer.getWindow(), &xpos, &ypos);
		pixelX = ( xpos - ( 1920 ) ) / 1920;
		pixelY = 1 - (2.0 * ypos) / 1080;
		if (glfwGetMouseButton(mainRenderer.getWindow(), GLFW_MOUSE_BUTTON_1))
		{
			GameObject* gameObject = new GameObject();
			gameObject->addComponent<RigidBody2DComponent>();
			gameObject->addToInstance(mainRenderer._instance);
			gameObject->getTransform()->setPosition({ pixelX, pixelY, 0.0f });
			gameObject->getComponent<RigidBody2DComponent>()->setPrevPosition(gameObject->getTransform()->getPositionVec());
			physics.AddPhysicsObjects(gameObject);
		}
		physics.updatePhysics();
	}
	
}
