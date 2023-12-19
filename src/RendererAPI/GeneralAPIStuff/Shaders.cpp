#include "Shaders.h"

namespace GeneralAPIs
{
	void Shaders::initializeShader(const std::string& shaderPath)
	{
		_path = shaderPath;
		parseAndLoadShader();
	}
}

