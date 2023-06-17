#pragma once
#include "Transform.h"

struct Instance
{
	glm::vec4 Color;
	Transform TransformData;
	Instance(Transform& transform);
};

