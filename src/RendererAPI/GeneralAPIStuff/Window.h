#pragma once
#include <iostream>
#include "Context.h"
namespace GeneralAPIs
{

	class Window
	{
	public:		// Methods
		Window(int width, int height, const std::string& title, std::unique_ptr<Context> context);
		virtual ~Window() = default;
		virtual bool isRendering() = 0;
		virtual void setAntiAliasing(bool toggle) = 0;
		virtual void pollEvents() = 0;
		virtual void swapBuffers() = 0;
		virtual void terminate() = 0;
		void updateWindow();
		
	protected:	// Methods

	protected:
		std::unique_ptr<Context> _currentContext;
		static uint8_t s_WindowsActive;
	private:	// Members
		void* _windowPtr;
		bool _isAntiAliasingActive;
		WindowProperties _properties;

	};
}


