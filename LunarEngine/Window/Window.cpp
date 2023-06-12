#include "Window.h"

Window::Window(unsigned int antiAliasing, unsigned int majorVersion, unsigned int minorVersion, unsigned int width, unsigned int height, GLint glProfile, const std::string title):
_antiAliasing(antiAliasing), _majorVersion(majorVersion), _minorVersion(minorVersion), _width(width), _height(height), _glProfile(glProfile), _title(title)
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    // Set the window creation hints
    glfwWindowHint(GLFW_OPENGL_PROFILE, _glProfile);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _minorVersion);

    // Create the GLFW window object
    _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
    if (!_window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }
    assignAsCurrentContext();
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    initializeGlad();
    changeViewport(0, 0, _width, _height);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

GLFWwindow* Window::getWindow() const
{
    return _window;
}

void Window::assignAsCurrentContext() const
{
    glfwMakeContextCurrent(_window);
}

void Window::changeViewport(GLint x, GLint y, GLsizei width, GLsizei height) const
{
    glViewport(x, y, width, height);
}

void Window::update()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
    processInput();

}

int Window::initializeGlad() const
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    return 0;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::processInput()
{
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(_window, true);
    }
}
