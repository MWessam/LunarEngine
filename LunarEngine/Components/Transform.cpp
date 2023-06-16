#include "Transform.h"
#include <iostream>

constexpr glm::vec3 Transform::ORIGINUPVECTOR = { 0.0f, 1.0f, 0.0f };
constexpr glm::vec3 Transform::ORIGINRIGHTVECTOR = { 1.0f, 0.0f, 0.0f };
constexpr glm::vec3 Transform::ORIGINFORWARDVECTOR = { 0.0f, 0.0f, -1.0f };

Transform::Transform()
{
	readyRotationQuaternion();	// Initialize rotation quat first just to avoid uninitialized bugs
	readyTransformMatrix();
}

const glm::mat4& Transform::getTransformMatrix() const
{
	return _transformMatrix;
}
const glm::quat& Transform::getRotationQuaternion() const
{
	return _rotationQuaternion;
}

const glm::vec3& Transform::getForward() const
{
	return _forwardVector;
}

const glm::vec3& Transform::getRight() const
{
	return _rightVector;
}

const glm::vec3& Transform::getUp() const
{
	return _upVector;
}

void Transform::setScale(glm::vec3 scaleVector)
{
	_scale = scaleVector;
	readyTransformMatrix();
}


void Transform::moveBenchmark() 
{
	_position.x += sin(_position.x);
}

void Transform::setPosition(glm::vec3 positionVector)
{
	_position = positionVector;
	readyTransformMatrix();
}

void Transform::setRotation(glm::vec3 rotationVector)
{
	_rotation = rotationVector;
	readyTransformMatrix();
	readyForwardVector();
}

void Transform::setRotation(glm::quat quaternionRotation)
{
	_rotationQuaternion = quaternionRotation;
	readyTransformMatrix();
}

void Transform::scale(float factor)
{
	_scale = { factor, factor, factor };
	readyTransformMatrix();
}


void Transform::readyTransformMatrix()
{
	glm::mat4 rotationMatrix = glm::toMat4(_rotationQuaternion);
	glm::mat4 model(1.0f);
	model = glm::translate(model, _position) * glm::toMat4(glm::quat(_rotation)) * glm::scale(model, _scale);
	_transformMatrix = model;
	_rotation = glm::eulerAngles(_rotationQuaternion);
	readyForwardVector();
	readyRightVector();
	readyUpVector();
	readyRotationQuaternion();
}

void Transform::readyRotationQuaternion()
{
	_rotationQuaternion = glm::quat(_rotation);
}

void Transform::readyForwardVector()
{
	_forwardVector = glm::vec3(_transformMatrix[0][2], _transformMatrix[1][2], _transformMatrix[2][2]);
}

void Transform::readyUpVector()
{
	_upVector = glm::vec3(_transformMatrix[0][1], _transformMatrix[1][1], _transformMatrix[2][1]);

}

void Transform::readyRightVector()
{
	_rightVector = glm::vec3(_transformMatrix[0][0], _transformMatrix[1][0], _transformMatrix[2][0]);

}

const glm::vec3& Transform::getPositionVec() const
{
	return _position;
}

const glm::vec3& Transform::getRotationVec() const
{
	return _rotation;
}

const glm::vec3& Transform::getScaleVec() const
{
	return _scale;
}

void Transform::lerpTowards(glm::vec3 targetPosition, float timeStep, float lerpSpeed)
{
	float lerpFactor = glm::clamp(timeStep * lerpSpeed, 0.0f, 1.0f);
	_position = glm::mix(_position, targetPosition, lerpFactor);
	readyTransformMatrix();
}

void Transform::rotate(glm::quat quaternionRotation)
{
	_rotationQuaternion = _rotationQuaternion * quaternionRotation;
	readyTransformMatrix();
}

void Transform::lerpTowards(Transform* target, float timeStep, float lerpSpeed)
{
	float lerpFactor = glm::clamp(timeStep * lerpSpeed, 0.0f, 1.0f);
	_position = glm::mix(_position, target->getPositionVec(), lerpFactor);
	readyTransformMatrix();
}

void Transform::slerpTowards(glm::quat targetRotation, float timeStep, float lerpSpeed)
{
	float lerpFactor = glm::clamp(timeStep * lerpSpeed, 0.0f, 1.0f);
	_rotationQuaternion = glm::slerp(_rotationQuaternion, targetRotation, lerpFactor);
	readyTransformMatrix();
}

void Transform::slerpTowards(Transform* target, float timeStep, float lerpSpeed)
{
	float lerpFactor = glm::clamp(timeStep * lerpSpeed, 0.0f, 1.0f);
	_rotationQuaternion = glm::slerp(_rotationQuaternion, target->getRotationQuaternion(), lerpFactor);
	readyTransformMatrix();
}