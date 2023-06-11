#pragma once
#include "Window.h"
#include "GameObject.h"
#include <ctime>
#include <vector>
class Renderer
{
private:
	Window* _window;
	GLFWwindow* _windowContextCached;
	clock_t _lastTime = clock();
	std::vector<GameObject*> _gameObjects;
	float calculateDeltaTime();
public:
	Renderer(Window* window);
	bool update();
	void addGameObject(GameObject* gameObject);





	~Renderer();

};

