#include "GameObject.h"

void GameObject::updateAll(float dt)
{
	for (GObjectComponent* component : _components) 
	{
		if (component->getEnabledState()) 
		{
			component->update(dt);
		}
	}
}
void GameObject::addComponent(GObjectComponent* component)
{
	_components.push_back(component);
}
template<typename T>
inline T* GameObject::getComponent() const
{
	for (GObjectComponent* component : _components)
	{
		T* r = dynamic_cast<T*>(component);
		if (r != nullptr)
		{
			return r;
		}
	}
	return nullptr;
}

