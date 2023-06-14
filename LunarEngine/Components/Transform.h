#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
// LEAVE FOR NOW (TEST ONLY)
class Transform
{
public:
    Transform();
    glm::mat4 getTransformMatrix() const;
    void move(float x, float y, float z);
private:
    glm::vec3 _position = { 0.0f, 0.0f, 0.0f };
    glm::vec3 _rotation = { 0.0f, 0.0f, 0.0f };
    glm::vec3 _scale = { 1.0f, 1.0f, 1.0f };
};

