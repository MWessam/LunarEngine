#include "LunaEngineAPI/Shaders.h"
#include "RendererAPI.h"

namespace GeneralAPIs
{
	void Shaders::initializeShader(const std::string& shaderPath)
	{
		_path = shaderPath;
		parseAndLoadShader();
	}
    void ShaderLibrary::Add(const std::string& name, const std::shared_ptr<Shaders>& shader)
    {
        LUN_CORE_ASSERT(!Exists(name), "Shader already exists!");
        _shaders[name] = shader;
    }

    std::shared_ptr<Shaders>& ShaderLibrary::Load(const std::string& name, const std::string& filepath)
    {
        auto shader = RendererAPI::S_API->createShader(name, filepath);
        Add(name, shader);
        return shader;
    }

    std::shared_ptr<Shaders>& ShaderLibrary::Get(const std::string& name)
    {
        LUN_CORE_ASSERT(Exists(name), "Shader not found!");
        return _shaders[name];
    }

    bool ShaderLibrary::Exists(const std::string& name) const
    {
        return _shaders.find(name) != _shaders.end();
    }
}