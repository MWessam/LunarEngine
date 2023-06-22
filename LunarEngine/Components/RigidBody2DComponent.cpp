#include "RigidBody2DComponent.h"

const glm::vec3 RigidBody2DComponent::getVelocity() const
{
    return _velocity;
}

const glm::vec3 RigidBody2DComponent::getAcceleration() const
{
    return _acceleration;
}

const glm::vec3 RigidBody2DComponent::getPrevPosition() const
{
    return _prevPosition;
}

const float RigidBody2DComponent::getMass() const
{
    return _mass;
}

const PhysicalMaterial* RigidBody2DComponent::getPhysicsMaterial() const
{
    return &_physicsMaterial;
}

void RigidBody2DComponent::setVelocity(const glm::vec3& velocity)
{
    _velocity = velocity;
}

void RigidBody2DComponent::setPrevPosition(const glm::vec3& position)
{
    _prevPosition = position;
}
