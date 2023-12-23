#pragma once
#include "LunaEngineAPI/Core/LunarIncludes.h"
#include <glm/glm.hpp>
namespace GeneralAPIs
{
    class Shaders
	{
	public:		// Methods
		virtual ~Shaders() = default;
        Shaders(const std::string& name, const std::string& path)
        :_name(name), _path(path)
        {
            parseAndLoadShader();
        }
        //Abstracts
		virtual void bind() = 0;
		virtual void unbind() = 0;
        virtual const std::string& GetName() const = 0;
        virtual uint32_t getUniformLocation(const std::string& name) const = 0;
        virtual void SetInt(const std::string& name, int value) = 0;
        virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
        virtual void SetFloat(const std::string& name, float value) = 0;
        virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
        virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
        virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
        virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

		void initializeShader(const std::string& shaderPath);

	protected:	// Methods
		virtual void parseAndLoadShader() = 0;

    protected:
		std::string _path;
        std::string _name;
	};
    class ShaderLibrary
    {
    public:
        void Add(const std::string& name, const std::shared_ptr<Shaders>& shader);
        std::shared_ptr<Shaders>& Load(const std::string& name, const std::string& filepath);
        std::shared_ptr<Shaders>& Get(const std::string& name);
        bool Exists(const std::string& name) const;
    private:
        std::unordered_map<std::string, std::shared_ptr<Shaders>> _shaders;
    };
}


