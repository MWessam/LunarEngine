#include "RendererAPI.h"
#include "Platforms/ogl/OpenGLAPI.h"

std::unique_ptr<RendererAPI> RendererAPI::create()
{
	switch (s_API)
	{
		case API::OpenGL:
			std::unique_ptr<OpenGLAPI> apiPtr(new OpenGLAPI());
			return std::move(apiPtr)
	}
}
