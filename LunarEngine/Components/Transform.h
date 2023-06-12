#pragma once
#include "GObjectComponent.h"
// LEAVE FOR NOW (TEST ONLY)
class Transform :
    public GObjectComponent
{
public:
    Transform(GameObject* owner);
private:
    void awake() override;
};

