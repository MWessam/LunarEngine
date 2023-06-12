#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Transform.h"
class GraphicsRenderer
{
protected:
	Shader* _shader;
	Texture* _texture;
	glm::vec4 _color;
public:
	GraphicsRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color);
	virtual ~GraphicsRenderer();
	virtual void render(const glm::mat4& projection, const glm::mat4& view, const Transform& transform) = 0;
	void setColor(const glm::vec4& color);
};

