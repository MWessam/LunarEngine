#pragma once
#include <vector>
#include "GObjectComponent.h"
#include "InstanceRenderer.h"
#include "Transform.h"
class Renderer;
//TODO: Implement Enableable class
class GameObject/*: public Enableable*/
{
private:
	GameObject* _parent;
	std::vector<GObjectComponent*> _components;
	Transform _transform;
	Instance _instance;
	InstanceRenderer* _objectRenderer;
	std::vector<GameObject*> children;
protected:
	void updateAll(float dt);
	void render(const glm::mat4& projection, const glm::mat4& view);
	friend Renderer;
public:
	GameObject(InstanceRenderer* instance);
	template <typename T>
	void addComponent();
	InstanceRenderer* getGraphicsRenderer();
	Transform* getTransform();
	template <typename T>
	T* getComponent() const;
	bool getEnabledState() const { return true; }
	
};

