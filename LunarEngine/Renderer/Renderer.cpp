#include "Renderer.h"
#include <random>
float Renderer::calculateDeltaTime()
{
    clock_t currentTime = clock();
    float delta = (float)(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
    return delta;
}
Renderer::Renderer(Window* window, Camera* camera):
    _window(window), _windowContextCached(window->getWindow()), _currentCamera(camera)
{
}

bool Renderer::clear()
{
    float dt = calculateDeltaTime();
    std::cout << 1 / dt << std::endl;
    return renderWindow(dt);
}
bool Renderer::renderWindow(float dt)
{
    if (!glfwWindowShouldClose(_windowContextCached))
    {
        _window->clear();
        updateObjects(dt);
        renderObjects();
        _window->update();
        return true;
    }
    return false;
}
void Renderer::renderObjects()
{
    for (GameObject* gameObject : _gameObjects)
    {
        if (gameObject->getEnabledState())
        {
            gameObject->render(_currentCamera->getProjectionMatrix(), _currentCamera->getViewMatrix());
            gameObject->getTransform()->scale((rand() / (double)RAND_MAX) * 2 - 1); //BENCHMARK ONLY
        }
    }
}
void Renderer::updateObjects(float dt)
{
    for (GameObject* gameObject : _gameObjects) 
    {
        if (gameObject->getEnabledState())
        {
            gameObject->updateAll(dt);
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
Renderer::~Renderer() 
{
    deleteObjects();
    glfwTerminate();
}
