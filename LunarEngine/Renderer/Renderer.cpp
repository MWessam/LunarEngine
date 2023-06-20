#include "Renderer.h"
#include <random>
void Renderer::calculateDeltaTime()
{
    clock_t currentTime = clock();
    DeltaTime = (float)(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
}
Renderer::Renderer()
    :_instance(GL_STATIC_DRAW)
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
        _window.clear();
        renderScene();
        _window.update();
        return true;
    }
    return false;
}

void Renderer::renderScene()
{
    _instance.draw(_currentCamera.getProjectionMatrix() * _currentCamera.getViewMatrix());
}


void Renderer::printFPS()
{
    std::cout << 1 / DeltaTime << std::endl;
}
void Renderer::setCurrentScene(Scene scene)
{
    //_currentScene = scene;
}
void Renderer::createCamera(float fov)
{
    _currentCamera.createCamera(fov);
}
void Renderer::createInstance()
{
    _instance.instantiate();
    _instance.setShader("../LunarEngine/Graphics/ShaderSource/Default.shader");
    _instance.setTexture("../LunarEngine/Graphics/Textures/cat.png");
}
InstanceRenderer* Renderer::getInstance()
{
    return &_instance;
}
void Renderer::createWindow(unsigned int width, unsigned int height, const std::string title)
{
    _window.createWindow(4, 4, 6, width, height, GLFW_OPENGL_CORE_PROFILE, title);
    _windowContextCached = _window.getWindow();
    _window.setColor({ 0.3f, 0.3f, 0.3f, 1.0f });

}
Renderer::~Renderer() 
{
    glfwTerminate();
}
