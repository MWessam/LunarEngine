#include "GObjectComponent.h"
#include"GameObject.h"

GObjectComponent::GObjectComponent(GameObject* owner):
	_owner(owner)
{
}

GameObject* GObjectComponent::getOwner() const
{
	return _owner;
}
