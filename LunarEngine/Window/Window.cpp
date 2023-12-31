#include "Window.h"

Window::Window()
{
}

void Window::createWindow(unsigned int antiAliasing, unsigned int majorVersion, unsigned int minorVersion, unsigned int width, unsigned int height, GLint glProfile, const std::string title)
{

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    // Set the window creation hints
    glfwWindowHint(GLFW_OPENGL_PROFILE, glProfile);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);

    // Create the GLFW window object
    _window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!_window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }
    assignAsCurrentContext();
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    initializeGlad();
    changeViewport(0, 0, width, height);
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


void Window::setColor(glm::vec4 color)
{
    _screenColor = color;
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

void Window::clear()
{
    glCall(glClearColor(_screenColor.x, _screenColor.y, _screenColor.z, _screenColor.w));
    glCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Window::update()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
    processInput();
}
