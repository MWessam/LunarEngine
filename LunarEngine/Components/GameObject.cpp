#include "GameObject.h"
#include "Renderer/Renderer.h"

void GameObject::updateAll(float dt)		// Updates all active components.
{
	for (GObjectComponent* component : _components) 
	{
		if (component->getEnabledState()) 
		{
			component->clear(dt);
		}
	}
}
void GameObject::render(const glm::mat4& projection, const glm::mat4& view)
{
	_objectRenderer.render(projection, view);
}
GameObject::GameObject():
	_objectRenderer(GL_STATIC_DRAW)
{
	_objectRenderer.setTransform(&_transform);
	_objectRenderer.instantiate();
}



Transform* GameObject::getTransform()
{
	return &_transform;
}
template<typename T>
void GameObject::addComponent()		// Add components only if theyre not already added. //TODO: IMPLEMENT A LOG SYSTEM
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
inline T* GameObject::getComponent() const		// Return component if it exists
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
GraphicsRenderer* GameObject::getGraphicsRenderer() 
{
	return &_objectRenderer;
}

