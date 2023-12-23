#include "OpenGLPlatform/OpenGLShaders.h"
#include <fstream>
#include <sstream>

namespace OpenGL
{
	OpenGLShaders::~OpenGLShaders()
	{
		unbind();
		glCall(glDeleteProgram(_id));
	}

	void OpenGLShaders::bind()
	{
		glCall(glUseProgram(_id));
	}

	void OpenGLShaders::unbind()
	{
		glCall(glUseProgram(0));
	}

	void OpenGLShaders::parseAndLoadShader()
	{
		createShader(parseShader());
	}

	OpenGLShaders::ShaderProgramSource OpenGLShaders::parseShader()
	{
        enum class ShaderType
        {
            NONE = -1, VERTEX = 0, FRAGMENT = 1, TESSELATION = 2, GEOMETRY = 3
        };

        std::ifstream stream(_path);
        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;

        while (getline(stream, line))
        {
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
            {
                ss[(int)type] << line << '\n';
            }
        }

        return { ss[0].str(), ss[1].str() };
	}
    uint16_t OpenGLShaders::compileShader(GLuint type, const std::string& source)
    {
        glCall(unsigned int id = glCreateShader(type));
        const char* src = source.c_str();
        glCall(glShaderSource(id, 1, &src, nullptr));
        glCall(glCompileShader(id));

        // Error handling
        int result;
        glCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
        std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
        if (result == GL_FALSE)
        {
            int length;
            glCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
            char* message = (char*)_malloca(length * sizeof(char));
            glCall(glGetShaderInfoLog(id, length, &length, message));
            std::cout
                << "Failed to compile "
                << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                << "shader"
                << std::endl;
            std::cout << message << std::endl;
            glCall(glDeleteShader(id));
            return 0;
        }
        return id;
    }
    void OpenGLShaders::createShader(const ShaderProgramSource& shaders)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = compileShader(GL_VERTEX_SHADER, shaders.VertexSource);
        unsigned int fs = compileShader(GL_FRAGMENT_SHADER, shaders.FragmentSource);
        glCall(glAttachShader(program, vs));
        glCall(glAttachShader(program, fs));

        glCall(glLinkProgram(program));

        GLint program_linked;

        glCall(glGetProgramiv(program, GL_LINK_STATUS, &program_linked));
        std::cout << "Program link status: " << program_linked << std::endl;
        if (program_linked != GL_TRUE)
        {
            GLsizei log_length = 0;
            GLchar message[1024];
            glCall(glGetProgramInfoLog(program, 1024, &log_length, message));
            std::cout << "Failed to link program" << std::endl;
            std::cout << message << std::endl;
        }

        glCall(glValidateProgram(program));
        glCall(glDeleteShader(vs));
        glCall(glDeleteShader(fs));

        _id = program;
    }
}

