#include "Camera.h"

Camera::Camera(float camWidth, float camHeight):
	_camWidth(camWidth), _camHeight(camHeight)
{
	glm::vec4 position = _camTransform.getTransformMatrix()[3];
	_projectionMatrix = glm::perspective(45.0f, 16 / 9.0f, 0.1f, 10.0f);
}

const Transform& Camera::getCamTransform() const
{
	return _camTransform;
}

const glm::mat4& Camera::getProjectionMatrix() const
{
	return _projectionMatrix;
	// TODO: insert return statement here
}

const glm::mat4 Camera::getViewMatrix() const
{
	return _view;
}
