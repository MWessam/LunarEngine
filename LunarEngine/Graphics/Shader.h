#pragma once
#include<glm/glm.hpp>
#include "string"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
class Shader
{
private:
	unsigned int _shaderID;
	std::unordered_map<std::string, int> _uniformLocationCache;
public:
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};
	Shader(const std::string& filePath);
	~Shader();

	unsigned int getShaderId() const;
	void bind() const;
	void unBind() const;
	void useProgram() const;
	void unuseProgram() const;
	void setUniform1i(const std::string& name, int value);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
	void setUniformMat4(const std::string& name, int count, bool transpose, const float* valuePtr);
private:
	static ShaderProgramSource parseShader(const std::string& filePath);
	static unsigned int compileShader(unsigned int type, const std::string& source);
	static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	int getUniformLocation(const std::string& name);


};

