#include "GraphicsRenderer.h"

GraphicsRenderer::GraphicsRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color):
	_shader(new Shader(shaderFile)), _texture(new Texture(textureFile)), _color(color)
{
}

GraphicsRenderer::~GraphicsRenderer()
{
	_shader->~Shader();
	_texture->~Texture();
}

void GraphicsRenderer::setColor(const glm::vec4& color)
{
	_color = color;
}

