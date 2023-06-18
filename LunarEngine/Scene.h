#pragma once
#include "Components/GameObject.h"
#include "Camera.h"
#include "InstanceRenderer.h"
class Scene
{
private:
	// Nodes/Gameobjects (Every object got pointer to parent and a vector of children)
	std::vector<GameObject*> _gameObjects;
	std::vector<InstanceRenderer*> _instances;
	Camera _camera;
public:
	void addGameObject(GameObject* gameObject);
};

