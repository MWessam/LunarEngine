#include "OpenGlContext.h"

OpenGL::OpenGlContext::~OpenGlContext()
{
	glfwTerminate();
}

void OpenGL::OpenGlContext::initContext(const GeneralAPIs::WindowProperties& properties)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		_glWindow = NULL;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	_glWindow = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), NULL, NULL);
	initRendererToContext();
	adjustViewport(0, 0, properties.Width, properties.Height);
}

void OpenGL::OpenGlContext::initRendererToContext()
{
	glfwMakeContextCurrent(_glWindow);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		_glWindow = NULL;
	}
}

void* OpenGL::OpenGlContext::getContext()
{
	return _glWindow;
}

void OpenGL::OpenGlContext::adjustViewport(uint16_t lowerLeftCornerX, uint16_t lowerLeftCornerY, uint16_t width, uint16_t height)
{
	glViewport(lowerLeftCornerX, lowerLeftCornerY, width, height);
}
