#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
// LEAVE FOR NOW (TEST ONLY)
class Transform
{
public:
    //Constants
    static const glm::vec3 ORIGINUPVECTOR;
    static const glm::vec3 ORIGINRIGHTVECTOR;
    static const glm::vec3 ORIGINFORWARDVECTOR;

    //Testing
    void moveBenchmark();

    //Constructors
    Transform();

    //Getters
    const glm::mat4& getTransformMatrix() const;
    const glm::vec3& getPositionVec() const;
    const glm::vec3& getRotationVec() const;
    const glm::vec3& getScaleVec() const;
    const glm::quat& getRotationQuaternion() const;
    const glm::vec3& getForward() const;
    const glm::vec3& getRight() const;
    const glm::vec3& getUp() const;


    //SETTERS
    //Vector Inputs
    void setPosition(glm::vec3 positionVector);
    void setRotation(glm::vec3 rotationVector);
    void setScale(glm::vec3 scaleVector);

    //Float Inputs
    void scale(float factor);

    //Quaternion Input
    void setRotation(glm::quat quaternionRotation);
    void rotate(glm::quat quaternionRotation);

    //Lerping Slerping
    void lerpTowards(glm::vec3 target, float timeStep, float lerpSpeed);
    void slerpTowards(glm::quat target, float timeStep, float lerpSpeed);
    void lerpTowards(Transform* target, float timeStep, float lerpSpeed);
    void slerpTowards(Transform* target, float timeStep, float lerpSpeed);

    //Lazy evaluation
    void readyTransformMatrix();
    void readyRotationQuaternion();
    void readyForwardVector();
    void readyUpVector();
    void readyRightVector();
private:
    //Values
    glm::vec3 _position = { 0.0f, 0.0f, 0.0f };
    glm::vec3 _rotation = { 0.0f, 0.0f, 0.0f };
    glm::vec3 _scale = { 1.0f, 1.0f, 1.0f };
    glm::quat _rotationQuaternion;
    glm::mat4 _transformMatrix;
    glm::vec3 _forwardVector = ORIGINFORWARDVECTOR;
    glm::vec3 _upVector = ORIGINUPVECTOR;
    glm::vec3 _rightVector = ORIGINRIGHTVECTOR;

};

