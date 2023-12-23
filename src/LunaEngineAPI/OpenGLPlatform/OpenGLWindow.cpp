#include "OpenGLPlatform/OpenGLWindow.h"
#include "OpenGLPlatform/OpenGlContext.h"

OpenGL::OpenGLWindow::OpenGLWindow(int width, int height, const std::string& title, std::unique_ptr<GeneralAPIs::Context> context):
GeneralAPIs::Window(width, height, title, std::move(context))
{
	_contextCached = (GLFWwindow*)_currentContext->getContext();
}

OpenGL::OpenGLWindow::~OpenGLWindow()
{
	terminate();
}

bool OpenGL::OpenGLWindow::isRendering()
{
	return !(glfwGetKey(_contextCached, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(_contextCached));
}

void OpenGL::OpenGLWindow::setAntiAliasing(bool toggle)
{

}

void OpenGL::OpenGLWindow::pollEvents()
{
	glfwPollEvents();
}

void OpenGL::OpenGLWindow::swapBuffers()
{
	glfwSwapBuffers(_contextCached);
}

void OpenGL::OpenGLWindow::terminate()
{
	glfwDestroyWindow(_contextCached);
	if (--s_WindowsActive == 0)
	{
		glfwTerminate();
	}
}
