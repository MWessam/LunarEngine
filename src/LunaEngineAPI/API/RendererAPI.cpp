#include "RendererAPI.h"
#include "OpenGLAPI.h"
GeneralAPIs::API GeneralAPIs::RendererAPI::s_API = API::None;
std::shared_ptr<GeneralAPIs::RendererAPI> GeneralAPIs::RendererAPI::create(API api)
{
	s_API = api;
	switch (s_API)
	{
		case API::OpenGL:
			std::shared_ptr<OpenGL::OpenGLAPI> apiPtr(new OpenGL::OpenGLAPI());
			return apiPtr;
	}
}
