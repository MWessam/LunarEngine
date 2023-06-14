#pragma once
#include "Components/Transform.h"

class Camera
{
private:
	const glm::vec3 cameraUp = { 0.0f, 1.0f, 0.0f };
	const glm::vec3 target = { 0.0f, 0.0f, 0.0f };
	Transform _camTransform;
	float _camWidth;
	float _camHeight;
	glm::mat4 _projectionMatrix;
	glm::mat4 _view = glm::mat4(1.0f);
	void readyProjectionMatrix();
	void readyViewMatrix();

public:
	Camera(float camWidth, float camHeight);
	const Transform& getCamTransform() const;
	const glm::mat4& getProjectionMatrix();
	const glm::mat4& getViewMatrix();


};

