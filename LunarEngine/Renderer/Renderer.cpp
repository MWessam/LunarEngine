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
    std::string title = "Lunar Engine - FPS = " + std::to_string(1 / DeltaTime);
    glfwSetWindowTitle(_windowContextCached, title.c_str());
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
Camera* Renderer::getCamera()
{
    return &_currentCamera;
}
void Renderer::createOrthoCamera(float width, float height)
{
    _currentCamera.createOrthoCamera(width, height);
}
void Renderer::createPerspectiveCamera(float fov)
{
    _currentCamera.createPerspectiveCamera(fov);
}
void Renderer::createInstance()
{
    _instance.instantiate();
    _instance.setShader("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/ShaderSource/Default.shader");
    _instance.setTexture("D:/SwE/C#/LunarEngine/LunarEngine/Graphics/Textures/cat.png");
}
GLFWwindow* Renderer::getWindow() const
{
    return _windowContextCached;
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
