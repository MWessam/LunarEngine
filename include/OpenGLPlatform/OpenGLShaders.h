#pragma once
#include "Shaders.h"
#include "OpenGLAPI.h"
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
		OpenGLShaders(const std::string &name, const std::string &path) : Shaders(name, path) {}
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


