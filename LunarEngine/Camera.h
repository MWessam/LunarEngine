#pragma once
#include "Components/Transform.h"

// Perspective (FOV) camera to render on
class Camera	
{
private:
	//Constants
	const glm::vec3 cameraUp = { 0.0f, 1.0f, 0.0f };
	const glm::vec3 target = { 0.0f, 0.0f, 0.0f };

	//Components
	Transform* _camTransform;

	//Data
	float _fov;
	glm::mat4 _projectionMatrix;
	glm::mat4 _view = glm::mat4(1.0f);

	//Lazy evaluation methods to compute them.
	void readyProjectionMatrix();
	void readyViewMatrix();
public:
	//Constructors
	Camera(float fov);
	~Camera();

	//Getters
	Transform& getCamTransform();
	const glm::mat4& getProjectionMatrix();
	const glm::mat4& getViewMatrix();

	//Setters
	void setFOV(float fov);

	//TODO: Implement camera rotation and movement (Might use transform component too)
	
	// Take in value and subtract it from _fov to zoom.
	void zoomByFOV(float fov);	

	void moveCameraForward(float speed);

	// VERTICAL CAMERA ROTATION, INPUT MUST BE IN RADIANS!
	void cameraTilt(float vertical);	

	// HORIZONTAL CAMERA ROTATION, INPUT MUST BE IN RADIANS!
	void cameraYaw(float angleHorizontal);
};

