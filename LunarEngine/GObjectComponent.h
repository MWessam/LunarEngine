#pragma once
#include "Enableable.h"
class GameObject;		// Forward Declaration

class GObjectComponent : public Enableable	// Component that can be stored within gameobjects to add functionality
{
public:
	GObjectComponent(GameObject* owner);
	virtual void update(float dt) = 0;
	GameObject* getOwner() const;
	virtual ~GObjectComponent();
private:
	GameObject* _owner;
	virtual void awake() = 0;
	virtual void start() = 0;
};

