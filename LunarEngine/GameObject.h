#pragma once
#include <vector>
#include "GObjectComponent.h"
//TODO: Implement Enableable class
class GameObject: public Enableable
{
private:
	GameObject* parent;
	std::vector<GObjectComponent*> _components;
	std::vector<GameObject*> children;
public:
	void updateAll(float dt);
	void addComponent(GObjectComponent* component);
	template <typename T>
	T* getComponent() const;
};

