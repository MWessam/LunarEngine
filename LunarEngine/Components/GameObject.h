#pragma once
#include <vector>
#include "GObjectComponent.h"
#include "RigidBody2DComponent.h"
#include "InstanceRenderer.h"
//TODO: Implement Enableable class
class GameObject/*: public Enableable*/
{
private:
	GameObject* _parent;
	std::vector<GObjectComponent*> _components;
	Transform _transform;
	std::vector<GameObject*> children;
protected:
public:
	//Constructors
	GameObject();
	void updateAll(float dt);

	template <typename T>
	// Add components only if theyre not already added. //TODO: IMPLEMENT A LOG SYSTEM
	void addComponent();

	//Pass in an instance renderer reference, then add the current transform to it.
	void addToInstance(InstanceRenderer& instance);

	//Getters

	Transform* getTransform();
	// Return component if it exists
	template <typename T>
	T* getComponent() const;
	bool getEnabledState() const { return true; }
	
};

