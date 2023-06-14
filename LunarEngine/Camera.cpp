#include "Camera.h"
void Camera::readyProjectionMatrix()
{
	glm::vec3 cameraPos = _camTransform.getPosition();
	_projectionMatrix = glm::ortho(cameraPos.x - (_camWidth / 2.0f), cameraPos.x + (_camWidth / 2.0f),
		cameraPos.y - (_camHeight / 2.0f), cameraPos.y + (_camHeight / 2.0f), -1.0f, 1.0f);
}
void Camera::readyViewMatrix()
{
	_view = glm::lookAt(_camTransform.getPosition(), target, cameraUp);
}
Camera::Camera(float camWidth, float camHeight):
	_camWidth(camWidth), _camHeight(camHeight)
{
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
const glm::mat4 Camera::getViewMatrix()
{
	readyViewMatrix();
	return _view;
}
