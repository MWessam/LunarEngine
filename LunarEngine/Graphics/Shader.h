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
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};
public:

	//Constructors and destructor
	Shader(const std::string& filePath);
	~Shader();

	//Getters
	unsigned int getShaderId() const;
private:
	int getUniformLocation(const std::string& name);

public:
	//Mark as the current active shader program
	void useProgram() const;

	void unuseProgram() const;

	//Set uniforms
	void setUniform1i(const std::string& name, int value);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
	void setUniformMat4(const std::string& name, int count, bool transpose, const float* valuePtr);
private:

	//Read in the shader source file and compile it.
	static ShaderProgramSource parseShader(const std::string& filePath);
	static unsigned int compileShader(unsigned int type, const std::string& source);
	static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);


};

