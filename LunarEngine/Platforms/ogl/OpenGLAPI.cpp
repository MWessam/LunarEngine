#include "OpenGLAPI.h"
#include "OpenGLBuffers.h"
#include "OpenGLVertexArray.h"
#include "OpenGLShaders.h"
#include "OpenGlContext.h"
#include "OpenGLWindow.h"

namespace OpenGL
{
	void OpenGLAPI::initialize()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
	}

	void OpenGLAPI::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLAPI::setClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLAPI::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLAPI::setLineWidth(float width)
	{
		glLineWidth(width);
	}

	std::unique_ptr<GeneralAPIs::VertexBuffer> OpenGLAPI::createVertexBuffer()
	{
		return std::make_unique<OpenGL::VertexBuffer>();
	}
	std::unique_ptr<GeneralAPIs::IndexBuffer> OpenGLAPI::createIndexBuffer()
	{
		return std::make_unique<OpenGL::IndexBuffer>();
	}
	std::unique_ptr<GeneralAPIs::VertexArray> OpenGLAPI::createVAO()
	{
		return std::make_unique<OpenGL::VertexArray>();
	}
	std::unique_ptr<GeneralAPIs::Shaders> OpenGLAPI::createShader()
	{
		return std::make_unique<OpenGL::OpenGLShaders>();
	}
	std::unique_ptr<GeneralAPIs::Context> OpenGLAPI::createContext()
	{
		return std::make_unique<OpenGL::OpenGlContext>();
	}
	std::unique_ptr<GeneralAPIs::Window> OpenGLAPI::createWindow(int width, int height, const std::string& title, std::unique_ptr<GeneralAPIs::Context> context)
	{
		return std::make_unique<OpenGL::OpenGLWindow>(width, height, title, std::move(context));
	}
}
