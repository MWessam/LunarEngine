#pragma once
#include <iostream>
namespace GeneralAPIs
{
	class Shaders
	{
	public:		// Methods
		virtual ~Shaders() = default;


		virtual void bind() = 0;
		virtual void unbind() = 0;

		// Handle uniforms 
		// TODO: Figure out a way to have a generic template for all uniforms.

		void initializeShader(const std::string& shaderPath);

	protected:	// Methods
		virtual void parseAndLoadShader() = 0;
		std::string _path;
	};
}


