#include "GLDebug.h"
#include "Shader.h"

Shader::Shader(const std::string& filePath)
{
    ShaderProgramSource source = parseShader(filePath);

    std::cout << "VERTEX" << std::endl << source.VertexSource << std::endl;
    std::cout << "FRAGMENT" << std::endl << source.FragmentSource << std::endl;

    unsigned int shader = createShader(source.VertexSource, source.FragmentSource);
    _shaderID = shader;
}

Shader::~Shader()
{
    unBind();
    glCall(glDeleteProgram(_shaderID));
}

Shader::ShaderProgramSource Shader::parseShader(const std::string& filePath)
{
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::ifstream stream(filePath);
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

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
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
        char* message = (char*) _malloca(length * sizeof(char));
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

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

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

    return program;
}

unsigned int Shader::getShaderId() const
{
    return _shaderID;
}

void Shader::bind() const
{
    glCall(glUseProgram(_shaderID));
}

void Shader::unBind() const
{
    glCall(glUseProgram(0));
}

void Shader::useProgram() const
{
    glCall(glUseProgram(_shaderID));
}

void Shader::unuseProgram() const
{
    glCall(glUseProgram(0));
}


void Shader::setUniform1i(const std::string& name, int value)
{
    glCall(glUniform1i(getUniformLocation(name), value));
}

GLint Shader::getUniformLocation(const std::string& name)
{
    if (_uniformLocationCache.find(name) != _uniformLocationCache.end())
        return _uniformLocationCache[name];

    glCall(GLint location = glGetUniformLocation(_shaderID, name.c_str()));
    if (location == -1)
        std::cout << "No active uniform variable with name " << name << " found" << std::endl;

    _uniformLocationCache[name] = location;

    return location;
}

void Shader::setUniform1f(const std::string& name, float value)
{
    glCall(glUniform1f(getUniformLocation(name), value));
}

void Shader::setUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
{
    glCall(glUniform4f(getUniformLocation(name), f0, f1, f2, f3));
}

void Shader::setUniformMat4(const std::string& name, int count, bool transpose, const float* valuePtr)
{
    glCall(glUniformMatrix4fv(getUniformLocation(name), count, transpose, valuePtr));
}
