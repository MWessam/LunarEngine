#include "GameObject.h"


void GameObject::addToInstance(InstanceRenderer& instance)
{
	instance.addTransform(&_transform);
}

Transform* GameObject::getTransform()
{
	return &_transform;
}

GameObject::GameObject()
	:_transform()
{

}

template<typename T>
void GameObject::addComponent()		
{
	
	if (getComponent<T>() == nullptr)
	{
		_components.push_back(T());
		return;
	}
	//TODO: IMPLEMENT A LOG SYSTEM
	return;
}
template<typename T>
T* GameObject::getComponent() const		
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

