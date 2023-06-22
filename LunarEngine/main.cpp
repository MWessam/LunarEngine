#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "PhysicsEngine.h"
#include "Components/RigidBody2DComponent.h"
#include <thread>
#include <chrono>
bool isRunning = true;
enum renderType 
{
	MESHRENDER,
	SPRITERENDER
};
glm::vec3 getWorldPosition(double mouseX, double mouseY, Renderer* renderer);
void physicsLoop(PhysicsEngine& physics);

int main()
{
	Renderer mainRenderer;
	//mainRenderer.createOrthoCamera(20.0f, 20.0f);
	mainRenderer.createPerspectiveCamera(120.0f);
	mainRenderer.createWindow(1920, 1080, "Lunar Engine");
	mainRenderer.createInstance();
	double xpos = 0.0f;
	double ypos = 0.0f;
	double pixelX, pixelY;
	PhysicsEngine physics;

	//Multithread the physics process
	std::thread t1([&]() { physicsLoop(physics); });
	// Instantiating objects
	while (mainRenderer.clear())
	{
		glfwGetCursorPos(mainRenderer.getWindow(), &xpos, &ypos);
		if (glfwGetMouseButton(mainRenderer.getWindow(), GLFW_MOUSE_BUTTON_1))
		{
			GameObject* gameObject = new GameObject();
			gameObject->addComponent<RigidBody2DComponent>();
			gameObject->addToInstance(mainRenderer._instance);
			gameObject->getTransform()->setPosition(getWorldPosition(xpos, ypos, &mainRenderer));
			gameObject->getComponent<RigidBody2DComponent>()->setPrevPosition(gameObject->getTransform()->getPositionVec());
			physics.AddPhysicsObjects(gameObject);
		}	
	}
	isRunning = false;
	t1.join();
	
}
void physicsLoop(PhysicsEngine& physics)
{
	clock_t currentTime = clock();
	clock_t lastTime = currentTime;
	while (isRunning)
	{
		currentTime = clock();
		float deltaTime = (float)(currentTime - lastTime) / CLOCKS_PER_SEC;
		if (deltaTime >= FIXED_TIMESTEP)
		{
			physics.updatePhysics();
			lastTime = currentTime;
		}
	}
}

glm::vec3 getWorldPosition(double mouseX, double mouseY, Renderer* renderer)
{
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(renderer->getWindow(), &screenWidth, &screenHeight);

	// Convert mouse position to NDC coordinates
	float ndcX =  (2 * mouseX - screenWidth) / screenWidth;
	float ndcY = 1.0f - (2.0f * mouseY) / screenHeight;

	// Convert NDC coordinates to world position
	glm::vec4 rayClip(ndcX, ndcY, -1.0f, 1.0f);
	glm::vec4 rayEye = glm::inverse(renderer->getCamera()->getProjectionMatrix()) * rayClip;
	rayEye = glm::vec4(rayEye.x, rayEye.y, -1.0f, 0.0f);
	glm::vec3 rayDir = glm::normalize(glm::vec3(renderer->getCamera()->getViewMatrix() * rayEye));
	float distance = -renderer->getCamera()->getCamTransform()->getPositionVec().z / rayDir.z;
	glm::vec3 worldPos = renderer->getCamera()->getCamTransform()->getPositionVec() + distance * rayDir;
	return worldPos;
}
