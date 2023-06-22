#include "Camera.h"
void Camera::readyProjectionMatrix()
{
	switch (_type)
	{
		case Perspective:
			glm::vec3 cameraPos = _camTransform.getPositionVec();
			_projectionMatrix = glm::perspective(glm::radians(_fov), 1920 / 1080.0f, -0.1f, 0.5f);
			break;
		case Ortho:
			_projectionMatrix = glm::ortho(0.0f, _width, 0.0f, _height, -1.0f,1.0f);
	}
	//Perspective clip plane apparently can't have a negative near value (took me too long to figure out i feel bad lol)
}
void Camera::readyViewMatrix()
{
	glm::vec3 camPositionVector = _camTransform.getPositionVec();
	glm::vec3 camForward = glm::vec3(_camTransform.getTransformMatrix()[0][2], _camTransform.getTransformMatrix()[1][2], _camTransform.getTransformMatrix()[2][2]);
	glm::vec3 target = camPositionVector + camForward;
	_view = glm::lookAt(camPositionVector, target, _camTransform.getUp());
}
Camera::Camera()
{
}
void Camera::createPerspectiveCamera(float fov)
{
	if (fov > 120.0f)
		_fov = 120.0f;
	else if (fov < 30.0f)
		_fov = 30.0f;
	else
		_fov = fov;
	_camTransform.setPosition({ 0, 0, -1.3f});
	_type = Perspective;
	readyProjectionMatrix();
	readyViewMatrix();
}
void Camera::createOrthoCamera(float width, float height)
{
	_type = Ortho;
	_width = width;
	_height = height;
	_camTransform.setPosition({ 0, 0, -0.0f });
	readyProjectionMatrix();
	readyViewMatrix();
}
Camera::~Camera()
{
}
Transform* Camera::getCamTransform()
{
	readyViewMatrix();
	return &_camTransform;
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
	_camTransform.setPosition(_camTransform.getPositionVec() + (_camTransform.getForward() * -speed));
	readyViewMatrix();
}

void Camera::cameraTilt(float angleVertical)
{
	glm::quat rotationQuaternion = glm::angleAxis(angleVertical, _camTransform.getRight());
	_camTransform.rotate(rotationQuaternion);
	glm::mat4 rotationMatrix = glm::toMat4(_camTransform.getRotationQuaternion());
	readyViewMatrix();
}

// I NEED TO UNDERSTAND QUATERNIONS AND ROTATIONS FIRST CUZ THIS IS SO HARD :(
// DONE! NOW CAMERA CAN YAW
void Camera::cameraYaw(float angleHorizontal)
{
	glm::quat rotationQuaternion = glm::angleAxis(angleHorizontal, _camTransform.getUp());
	_camTransform.rotate(rotationQuaternion);
	glm::mat4 rotationMatrix = glm::toMat4(_camTransform.getRotationQuaternion());
	readyViewMatrix();
}


