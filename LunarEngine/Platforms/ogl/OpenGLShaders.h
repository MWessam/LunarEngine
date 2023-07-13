#pragma once
#include "RendererAPI/GeneralAPIStuff/Shaders.h"
#include "OpenGLAPI.h"
#include <unordered_map>
namespace OpenGL
{
	class OpenGLShaders
		: public GeneralAPIs::Shaders
	{
	private:	// Struct
		struct ShaderProgramSource
		{
			std::string VertexSource;
			std::string FragmentSource;
		};


	public:		// Methods
		OpenGLShaders() {}
		~OpenGLShaders() override;

		void bind() override;
		void unbind() override;

	protected:	// Methods
		void parseAndLoadShader() override;

	private:	// Methods
		ShaderProgramSource parseShader();
		uint16_t compileShader(GLuint type, const std::string& source);
		void createShader(const ShaderProgramSource& shaders);

	private:	// Members
		GLuint _id;
		std::unordered_map<std::string, int> _uniformLocationCache;
	};
}


