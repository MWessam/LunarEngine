#include "LunaEngineAPI/Window.h"
namespace GeneralAPIs
{
	uint8_t Window::s_WindowsActive = 0;
	Window::Window(int width, int height, const std::string& title, std::unique_ptr<Context> context)
	: _properties(width, height, title), _currentContext(std::move(context))
	{
		s_WindowsActive++;
		_currentContext->createContext(_properties);
	}
	void Window::updateWindow()
	{
		swapBuffers();
		pollEvents();
	}
}
