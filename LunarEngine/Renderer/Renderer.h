#pragma once
#include "Window/Window.h"
#include "Components/GameObject.h"
#include "Camera.h"
#include <ctime>
#include <vector>
#include "glm/glm.hpp"

class Renderer
{
private:
	Window* _window;
	Camera* _currentCamera;
	GLFWwindow* _windowContextCached;
	clock_t _lastTime = clock();
	std::vector<GameObject*> _gameObjects;
	float calculateDeltaTime();
	bool renderWindow(float dt);
	void renderObjects();
	void updateObjects(float dt);
	void clear(glm::vec4 color);
public:
	Renderer(Window* window, Camera* camera);
	bool update();
	void addGameObject(GameObject* gameObject);
	~Renderer();
};

