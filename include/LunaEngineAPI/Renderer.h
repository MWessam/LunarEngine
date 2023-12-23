#pragma once
#include "RendererAPI.h"
#include <ctime>
namespace Renderer
{
	//Encapsulate all the window/context stuff and will also provide an interface for our ECS
	//This class handles the per frame methods.
	class Renderer
	{

	public:		// Members
		float DeltaTime;
	public:		// Methods
		Renderer(std::shared_ptr<GeneralAPIs::RendererAPI> apiType);
		void createWindow(uint16_t width, uint16_t height, std::string title);
		bool render();
		void updateRenderer();

	private:	// Members
		std::shared_ptr<GeneralAPIs::RendererAPI> _api;
		std::unique_ptr<GeneralAPIs::Window> _window;
		clock_t _lastTime = clock();
	private:	// Methods
		void renderFrame();
		void updateScene();
		void calculateDeltaTime();

	};
}

