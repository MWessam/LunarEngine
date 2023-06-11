#include "Renderer.h"
float Renderer::calculateDeltaTime()
{
    clock_t currentTime = clock();
    float delta = (float)(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
    return delta;
}
Renderer::Renderer(Window* window):
    _window(window), _windowContextCached(window->getWindow())
{

}

bool Renderer::update()
{
    float dt = calculateDeltaTime();
    return renderWindow(dt);
}
bool Renderer::renderWindow(float dt)
{
    if (!glfwWindowShouldClose(_windowContextCached))
    {
        renderObjects(dt);
        _window->update();
        return true;
    }
    return false;
}
void Renderer::renderObjects(float dt)
{
    for (GameObject* gameObject : _gameObjects) 
    {
        if (gameObject->getEnabledState())
        {
            gameObject->updateAll(dt);
        }
    }
}
void Renderer::addGameObject(GameObject* gameObject)
{
    _gameObjects.push_back(gameObject);
}
Renderer::~Renderer() 
{
    glfwTerminate();
}
