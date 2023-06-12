#include "Transform.h"
#include <iostream>

Transform::Transform(GameObject* owner) : GObjectComponent(owner)
{
}

glm::mat4 Transform::getTransformMatrix() const
{
	glm::mat4 rotationMatrix = glm::toMat4(glm::quat(_rotation));
	glm::mat4 model(1.0f);
	model = glm::translate(model, _position) * rotationMatrix * glm::scale(model,_scale);
	return model;
}

void Transform::awake()
{
	GObjectComponent::awake();
	std::cout << "World" << std::endl;
}
