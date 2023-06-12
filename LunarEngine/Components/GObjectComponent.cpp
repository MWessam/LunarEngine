#include "GObjectComponent.h"
#include"GameObject.h"
#include <iostream>

GObjectComponent::GObjectComponent(GameObject* owner):
	_owner(owner)
{
}

GameObject* GObjectComponent::getOwner() const
{
	return _owner;
}

GObjectComponent::~GObjectComponent()
{
}

void GObjectComponent::init()
{
	awake();
}

void GObjectComponent::awake()
{
	std::cout << "Hello" << std::endl;
}

void GObjectComponent::start()
{
}

void GObjectComponent::onEnable()
{
}

void GObjectComponent::onDisable()
{
}
