#pragma once
#include <vector>
#include "GObjectComponent.h"
#include "GraphicsRenderer.h"
#include "Transform.h"
class Renderer;
//TODO: Implement Enableable class
class GameObject/*: public Enableable*/
{
private:
	GameObject* _parent;
	std::vector<GObjectComponent*> _components;
	Transform _transform;
	GraphicsRenderer _objectRenderer;
	std::vector<GameObject*> children;
protected:
	void updateAll(float dt);
	void render(const glm::mat4& projection, const glm::mat4& view);
	friend Renderer;
public:
	GameObject();
	template <typename T>
	void addComponent();
	GraphicsRenderer* getGraphicsRenderer();
	Transform* getTransform();
	template <typename T>
	T* getComponent() const;
	bool getEnabledState() const { return true; }
	
};

