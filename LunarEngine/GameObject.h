#pragma once
#include <vector>
#include "GObjectComponent.h"
class GameObject
{
private:
	std::vector<GObjectComponent*> _components;
public:
	void updateAll();

	void addComponent(GObjectComponent* component);
	template <typename T>
	T* getComponent() const;
};

