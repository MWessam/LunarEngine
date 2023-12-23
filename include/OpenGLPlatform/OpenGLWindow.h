#pragma once
#include "Window.h"
#include "OpenGLAPI.h"
namespace OpenGL
{
	class OpenGLWindow : public GeneralAPIs::Window
	{
	public:
		OpenGLWindow(int width, int height, const std::string& title, std::unique_ptr<GeneralAPIs::Context> context);
		~OpenGLWindow() override;
		bool isRendering() override;
		void setAntiAliasing(bool toggle) override;
		void pollEvents() override;
		void swapBuffers() override;
		void terminate() override;
	private:	// Members
		GLFWwindow* _contextCached;
	protected:	// Methods
	};
}