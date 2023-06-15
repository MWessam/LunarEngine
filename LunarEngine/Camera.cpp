#include "Camera.h"
void Camera::readyProjectionMatrix()
{
	glm::vec3 cameraPos = _camTransform.getPosition();
	_projectionMatrix = glm::perspective(90.0f, 1920 / 1080.0f, 0.0f, 0.5f);
	//Perspective clip plane apparently can't have a negative near value (took me too long to figure out i feel bad lol)
}
void Camera::readyViewMatrix()
{
	_view = glm::lookAt(_camTransform.getPosition(), target, cameraUp);
}
Camera::Camera(float camWidth, float camHeight):
	_camWidth(camWidth), _camHeight(camHeight)
{
	_camTransform.move(0, 0, -0.3);
	readyProjectionMatrix();
	readyViewMatrix();
}
const Transform& Camera::getCamTransform() const
{
	return _camTransform;
}
const glm::mat4& Camera::getProjectionMatrix()
{
	readyProjectionMatrix();
	return _projectionMatrix;
}
const glm::mat4& Camera::getViewMatrix()
{
	readyViewMatrix();
	return _view;
}
