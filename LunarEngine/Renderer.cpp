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

bool Renderer::Update()
{
    calculateDeltaTime();
    if (!glfwWindowShouldClose(_windowContextCached)) 
    {
        _window->update();
        return true;
    }
    return false;
}
void Renderer::AddGameObject(GameObject* gameObject)
{
    _gameObjects.push_back(gameObject);
}
Renderer::~Renderer() 
{
    glfwTerminate();
}
