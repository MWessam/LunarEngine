#include "Renderer.h"

namespace Renderer
{
	Renderer::Renderer(const GeneralAPIs::API& apiType):
		_api(GeneralAPIs::RendererAPI::create(apiType))
	{
	}
	void Renderer::createWindow(uint16_t height, uint16_t width, std::string title)
	{
		_window = _api->createWindow(width, height, title, _api->createContext());
	}
	bool Renderer::render()
	{
		calculateDeltaTime();
		bool renderingState = _window->isRendering();
		_api->clear();
		renderFrame();
		updateScene();
		_window->updateWindow();
		return renderingState;
	}
}
