#pragma once
#include <iostream>
namespace GeneralAPIs
{
	struct WindowProperties
	{
		int Width;
		int Height;
		std::string Title;
		WindowProperties(int width, int height, const std::string& title) :
			Width(width), Height(height), Title(title) {}
	};
}

