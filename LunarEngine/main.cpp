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
	Window mainwindow(4, 4, 6, 1920, 1080, GLFW_OPENGL_CORE_PROFILE, "Lunar Engine");
	Camera cam(90.0f);
	Renderer mainRenderer(&mainwindow, &cam);
	InstanceRenderer instance(GL_STATIC_DRAW);
	instance.setShader("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/ShaderSource/Default.shader");
	instance.setTexture("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/Textures/cat.png");
	std::vector<GameObject*> gameObjs;
	mainwindow.setColor({0.3f, 0.3f, 0.3f, 1.0f});
	for (int i = 0; i < 10000; i++)
	{
		GameObject gameObject;
		gameObject.addToInstance(instance);
		gameObjs.push_back(&gameObject);
	}
	mainRenderer._instance = &instance;
	while (mainRenderer.clear())
	{
		for (GameObject* gameobject : gameObjs)
		{
			gameobject->getTransform()->scale((rand() / (double)RAND_MAX) * 2 - 1);
		}

		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_W))
		{
			//PlayerTransform->setPosition(PlayerTransform->getPositionVec() + glm::vec3(0, 0.01f, 0));
			cam.moveCameraForward(-0.01f);
		}
		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_S))
		{
			//PlayerTransform->setPosition(PlayerTransform->getPositionVec() + glm::vec3(0, -0.01f, 0));
			cam.moveCameraForward(0.01f);

		}
		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_A))
		{
			cam.getCamTransform().setPosition(cam.getCamTransform().getPositionVec() + glm::vec3(0.01f, 0, 0));
		}
		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_D))
		{
			cam.getCamTransform().setPosition(cam.getCamTransform().getPositionVec() + glm::vec3(-0.01f, 0, 0));
		}
		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_LEFT_SHIFT))
			cam.cameraTilt(-0.01f);
		if (glfwGetKey(mainwindow.getWindow(), GLFW_KEY_LEFT_CONTROL))
			cam.cameraTilt(0.01f);
		////Apparently i cant follow the player object either...
		//cam.getCamTransform().setPosition(glm::vec3(PlayerTransform->getPositionVec().x, PlayerTransform->getPositionVec().y, cam.getCamTransform().getPositionVec().z));
		mainRenderer.printFPS();
	}
}
