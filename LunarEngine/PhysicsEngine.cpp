#include "PhysicsEngine.h"

void PhysicsEngine::AddPhysicsObjects(GameObject* gameObject)
{
	RigidBody2DComponent* rb = gameObject->getComponent<RigidBody2DComponent>();
	if (rb != nullptr)
	{
		ActivePhysicsObjects[rb] = gameObject->getTransform();
	}
	else
		std::cout << "DOESNT CONTAIN RIGIDBODY!" << std::endl;
}

void PhysicsEngine::updatePhysics()
{
	for (std::pair <RigidBody2DComponent*, Transform*> physObj : ActivePhysicsObjects)
	{
		glm::vec3 newPosition = physObj.second->getPositionVec() * 2.0f - physObj.first->getPrevPosition() + (GRAVITY * FIXED_TIMESTEP * FIXED_TIMESTEP);
		glm::vec3 newVelocity = ((newPosition - physObj.first->getPrevPosition()) / (2 * FIXED_TIMESTEP));
		physObj.first->setPrevPosition(physObj.second->getPositionVec());
		physObj.second->setPosition(newPosition);
		physObj.first->setVelocity(newVelocity);
	}
}
