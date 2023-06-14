#pragma once
#include "Components/Transform.h"

class Camera
{
private:
	Transform _camTransform;
	float _camWidth;
	float _camHeight;
	glm::mat4 _projectionMatrix;
	glm::mat4 _view = glm::mat4(1.0f);


public:
	Camera(float camWidth, float camHeight);
	const Transform& getCamTransform() const;
	const glm::mat4& getProjectionMatrix() const;
	const glm::mat4 getViewMatrix() const;


};

