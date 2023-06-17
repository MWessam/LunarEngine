#include "Renderer.h"
#include <random>
void Renderer::calculateDeltaTime()
{
    clock_t currentTime = clock();
    DeltaTime = (float)(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
}
Renderer::Renderer(Window* window, Camera* camera):
    _window(window), _windowContextCached(window->getWindow()), _currentCamera(camera)
{
}

bool Renderer::clear()
{
    calculateDeltaTime();
    return renderWindow();
}
bool Renderer::renderWindow()
{
    if (!glfwWindowShouldClose(_windowContextCached))
    {
        _window->clear();
        updateObjects();
        renderObjects();
        _window->update();
        return true;
    }
    return false;
}
void Renderer::renderObjects()
{
    for (InstanceRenderer* instance: _instances)
    {
        instance->render(_currentCamera->getProjectionMatrix(), _currentCamera->getViewMatrix());
        //gameObject->getTransform()->scale((rand() / (double)RAND_MAX) * 2 - 1); //BENCHMARK ONLY
    }
}
void Renderer::updateObjects()
{
    for (GameObject* gameObject : _gameObjects) 
    {
        if (gameObject->getEnabledState())
        {
            gameObject->updateAll(DeltaTime);
        }
    }
}

void Renderer::deleteObjects()
{
    for (GameObject* gameObject : _gameObjects)
    {
        delete gameObject;
    }
}

void Renderer::addGameObject(GameObject* gameObject)
{
    _gameObjects.push_back(gameObject);
}
void Renderer::printFPS()
{
    std::cout << 1 / DeltaTime << std::endl;
}
void Renderer::addInstance(InstanceRenderer* instance)
{
    _instances.push_back(instance);
}
Renderer::~Renderer() 
{
    deleteObjects();
    glfwTerminate();
}
