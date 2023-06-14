#pragma once
#include "Enableable.h"
//TODO: Implement Update and LateUpdate methods.
class GObjectComponent : public Enableable	// Component that can be stored within gameobjects to add functionality
{
public:
	GObjectComponent();
	virtual ~GObjectComponent();
	int getID();
	virtual void update(float dt) = 0;
	virtual void lateUpdate(float dt) = 0;
	virtual void init();
	virtual void awake() = 0;
	virtual void start() = 0;
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
protected:
	int _entityID;
private:
	static int s_LastID;
};

