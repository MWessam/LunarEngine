#pragma once
#include "Window/Window.h"
#include <ctime>
#include <vector>
#include "glm/glm.hpp"
#include "Scene.h"
//Main renderer for the current window context.
class Renderer
{
private:
	Window _window;
	Camera _currentCamera;
	GLFWwindow* _windowContextCached;
	clock_t _lastTime = clock();
	Scene _currentScene;
	void calculateDeltaTime();
	bool renderWindow();
	void renderScene();
public:
	InstanceRenderer _instance;
	Renderer();
	bool clear();
	void printFPS();
	void setCurrentScene(Scene scene);
	void createCamera(float fov);
	void createInstance();
	InstanceRenderer* getInstance();
	void createWindow(unsigned int width, unsigned int height, const std::string title);
	~Renderer();
	float DeltaTime = 0.0f;
};

