#pragma once
#include "RendererAPI/GeneralAPIStuff/Context.h"

#include "Platforms/ogl/OpenGLAPI.h"
namespace OpenGL
{
	class OpenGlContext :
		public GeneralAPIs::Context
	{
	public:		// Methods
		~OpenGlContext() override;
		void initContext(const GeneralAPIs::WindowProperties& properties) override;
		void initRendererToContext() override;
		void* getContext() override;
		void adjustViewport(uint16_t lowerLeftCornerX, uint16_t lowerLeftCornerY, uint16_t width, uint16_t height) override;

	private:	// Members
		GLFWwindow* _glWindow;

	};
}


