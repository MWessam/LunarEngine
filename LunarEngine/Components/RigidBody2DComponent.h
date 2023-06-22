#pragma once
#include "GObjectComponent.h"
#include "glm/glm.hpp"
struct PhysicalMaterial
{
	float Friction;
	float Elasticity;
};
enum ForceMode
{
	Force,
	Acceleration,
	Impulse
};

class RigidBody2DComponent
	: public GObjectComponent
{
private:
	glm::vec3 _velocity;
	glm::vec3 _acceleration;
	glm::vec3 _prevPosition;
	float _mass;
	PhysicalMaterial _physicsMaterial;
public:
	RigidBody2DComponent() = default;

	const glm::vec3 getVelocity() const;
	const glm::vec3 getAcceleration() const;
	const glm::vec3 getPrevPosition() const;
	const float getMass() const;
	const PhysicalMaterial* getPhysicsMaterial() const;
	
	void setVelocity(const glm::vec3& velocity);
	void setPrevPosition(const glm::vec3& position);

};

