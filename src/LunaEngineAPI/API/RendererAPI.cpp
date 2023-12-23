#include "RendererAPI.h"
#include "OpenGLAPI.h"
GeneralAPIs::API GeneralAPIs::RendererAPI::s_API = API::None;
std::shared_ptr<GeneralAPIs::RendererAPI> GeneralAPIs::RendererAPI::create(API api)
{
	s_API = api;
	switch (s_API)
	{
		case API::OpenGL:
			S_API = std::make_shared<OpenGL::OpenGLAPI>();
			return S_API;
        case API::DirectX11:
            break;
        case API::DriectX12:
            break;
        case API::Vulkan:
            break;
        case API::None:
            break;
    }
}

std::shared_ptr<GeneralAPIs::ShaderLibrary> GeneralAPIs::RendererAPI::createShaderLibrary() {
    return std::make_shared<GeneralAPIs::ShaderLibrary>();
}
