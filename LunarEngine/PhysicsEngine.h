#pragma once
#include "glm/glm.hpp"
#include <math.h>
#include <vector>
#include <map>
#include <memory>
#include "Components/GameObject.h"
#include "Components/RigidBody2DComponent.h"
const float FIXED_TIMESTEP = 1 / 60.0f;
const glm::vec3 GRAVITY = { 0, -9.80665f, 0 };
class PhysicsEngine
{
public:
	// GAME OBJECT MUST HAVE RIGIDBODY!
	std::unordered_map<RigidBody2DComponent*, Transform*> ActivePhysicsObjects;
	void AddPhysicsObjects(GameObject* gameObject);
	void updatePhysics();
private:
};

