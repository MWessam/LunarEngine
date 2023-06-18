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
        renderScene();
        _window->update();
        return true;
    }
    return false;
}

void Renderer::renderScene()
{
    _instance->draw(_currentCamera->getProjectionMatrix() * _currentCamera->getViewMatrix());
}


void Renderer::printFPS()
{
    std::cout << 1 / DeltaTime << std::endl;
}
void Renderer::setCurrentScene(Scene* scene)
{
    _currentScene = scene;
}
Renderer::~Renderer() 
{
    glfwTerminate();
}
