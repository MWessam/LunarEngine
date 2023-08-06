#pragma once
#include <cstdint>
#include "WindowProperties.h"
namespace GeneralAPIs
{
	class Context	// Window context it will render onto
	{
	public:		// Methods
		Context() {}
		virtual ~Context() = default;
		virtual void initContext(const WindowProperties& properties) = 0;
		virtual void initRendererToContext() = 0;
		virtual void adjustViewport(uint16_t lowerLeftCornerX, uint16_t lowerLeftCornerY, uint16_t width, uint16_t height) = 0;
		virtual void* getContext() = 0;
		void createContext(const WindowProperties& properties);

	protected:
		void* _window;

		

	};
}


