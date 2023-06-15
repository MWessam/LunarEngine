#include "Camera.h"
void Camera::readyProjectionMatrix()
{
	glm::vec3 cameraPos = _camTransform->getPositionVec();
	_projectionMatrix = glm::perspective(_fov, 1920 / 1080.0f, 0.0f, 0.5f);
	//Perspective clip plane apparently can't have a negative near value (took me too long to figure out i feel bad lol)
}
void Camera::readyViewMatrix()
{
	_view = glm::lookAt(_camTransform->getPositionVec(), _camTransform->getForward(), _camTransform->getUp());
}
Camera::Camera(float fov):
	_fov(fov)
{
	if (fov > 120.0f)
		_fov = 120.0f;
	else if (fov < 30.0f)
		_fov = 30.0f;
	_camTransform = new Transform();
	_camTransform->setPosition({ 0, 0, -1.3 });
	readyProjectionMatrix();
	readyViewMatrix();
}
Camera::~Camera()
{
	delete _camTransform;
}
Transform& Camera::getCamTransform()
{
	readyViewMatrix();
	return *_camTransform;
}
const glm::mat4& Camera::getProjectionMatrix()
{
	return _projectionMatrix;
}
const glm::mat4& Camera::getViewMatrix()
{
	return _view;
}

void Camera::setFOV(float fov)
{
	_fov = fov;
	readyProjectionMatrix();
}

void Camera::zoomByFOV(float addOntoFOV)
{
	_fov -= addOntoFOV;
	readyProjectionMatrix();
}

void Camera::moveCameraForward(float speed)
{
	_camTransform->setPosition(_camTransform->getPositionVec() + (_camTransform->getForward() * -speed));
	readyViewMatrix();
}

// I NEED TO UNDERSTAND QUATERNIONS AND ROTATIONS FIRST CUZ THIS IS SO HARD :(
void Camera::cameraYawn(float angleHorizontal)		
{
	glm::quat rotationQuaternion = glm::angleAxis(angleHorizontal, _camTransform->getUp());
	_camTransform->rotate(rotationQuaternion);
	glm::mat4 rotationMatrix = glm::toMat4(_camTransform->getRotationQuaternion());
	readyViewMatrix();
	_view = _view * rotationMatrix;
}


