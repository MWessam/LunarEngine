#include "GraphicsRenderer.h"

void GraphicsRenderer::createQuad(Transform* transform, int entityID)
{
	constexpr GLsizei vertexCount = 4;
	constexpr glm::vec4 textureCoords[] = { { 0.0f, 0.0f ,0.0f, 1.0f}, { 1.0f, 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } };
	for (GLsizei i = 0; i < vertexCount; i++) 
	{
		_object.Positions[i] = transform->getTransformMatrix() * _object.Positions[i];
		_object.TexCoord[i] = textureCoords[i];
	}
	_object.Color = _color;
	_object.EntityID = entityID;
	_object.TexIndex = 1;
}

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

