#include "GObjectComponent.h"
#include <iostream>
int GObjectComponent::s_LastID = 0;

GObjectComponent::GObjectComponent()
{
	_entityID = ++s_LastID;
}

GObjectComponent::~GObjectComponent()
{
}

int GObjectComponent::getID()
{
	return _entityID;
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
