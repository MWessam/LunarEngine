#include "Transform.h"
#include <iostream>

Transform::Transform(GameObject* owner) : GObjectComponent(owner)
{
}

void Transform::awake()
{
	GObjectComponent::awake();
	std::cout << "World" << std::endl;
}
