#pragma once
#include "Window/Window.h"
#include "GameObject.h"
#include <ctime>
#include <vector>
#include "glm/glm.hpp"
class Renderer
{
private:
	Window* _window;
	GLFWwindow* _windowContextCached;
	clock_t _lastTime = clock();
	std::vector<GameObject*> _gameObjects;
	float calculateDeltaTime();
	bool renderWindow(float dt);
	void renderObjects(float dt);
	void clear(glm::vec4 color);
public:
	Renderer(Window* window);
	bool update();
	void addGameObject(GameObject* gameObject);
	~Renderer();
};

