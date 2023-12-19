#include "Renderer.h"
#include <chrono>

namespace Renderer
{
	Renderer::Renderer(std::shared_ptr<GeneralAPIs::RendererAPI> api):
		_api(api), DeltaTime(0.0f)
	{
	}
	void Renderer::createWindow(uint16_t height, uint16_t width, std::string title)
	{
		_window = _api->createWindow(width, height, title, _api->createContext());
	}
	bool Renderer::render()
	{
		calculateDeltaTime();
		_api->clear();

		return _window->isRendering();
	}
	void Renderer::updateRenderer()
	{
		renderFrame();
		updateScene();
		_window->updateWindow();
	}
	void Renderer::renderFrame()
	{

	}
	void Renderer::updateScene()
	{
	}
	void Renderer::calculateDeltaTime()
	{
		clock_t currTime = clock();
		DeltaTime = (float)(currTime - _lastTime) / CLOCKS_PER_SEC;
		_lastTime = currTime;
	}
}
