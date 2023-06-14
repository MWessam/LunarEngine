#include "Transform.h"
#include <iostream>

Transform::Transform()
{
}

glm::mat4 Transform::getTransformMatrix() const
{
	glm::mat4 rotationMatrix = glm::toMat4(glm::quat(_rotation));
	glm::mat4 model(1.0f);
	model = glm::translate(model, _position) * rotationMatrix * glm::scale(model,_scale);
	return model;
}

void Transform::move(float x, float y, float z)
{
	_position.x += x;
	_position.y += y;
	_position.z += z;

}

void Transform::scale(float factor)
{
	_scale = { factor, factor, factor };
}
