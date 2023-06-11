#pragma once
#include "Enableable.h"
//TODO: Implement Update and LateUpdate methods.
class GameObject;		// Forward Declaration

class GObjectComponent : public Enableable	// Component that can be stored within gameobjects to add functionality
{
public:
	GObjectComponent(GameObject* owner);
	virtual void update(float dt) = 0;
	virtual void lateUpdate(float dt) = 0;
	GameObject* getOwner() const;
	virtual ~GObjectComponent();
	virtual void init();
protected:
	virtual void awake() = 0;
	virtual void start() = 0;
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
private:
	GameObject* _owner;
};

