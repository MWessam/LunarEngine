#include "GraphicsRenderer.h"

void GraphicsRenderer::createQuad(Transform* transform)
{
	constexpr GLsizei vertexCount = 4;
	for (GLsizei i = 0; i < vertexCount; i++) 
	{
		_object.Vertices[i].Position = _object.Vertices[i].Position * transform->getTransformMatrix();
	}
	_object.Color = _color;
	_object.TexIndex = 0;
}
GraphicsRenderer::GraphicsRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color, GLenum drawType) :
	_shader( new Shader(shaderFile)), _texture( new Texture(textureFile)), _color(color), _drawType(drawType)
{
}
GraphicsRenderer::GraphicsRenderer(const std::string& textureFile, GLenum drawType):
	_shader( new Shader(DEFAULTSHADER)), _texture( new Texture(textureFile)), _drawType(drawType)
{
}
GraphicsRenderer::GraphicsRenderer(GLenum drawType) :
	_shader(new Shader(DEFAULTSHADER)), _drawType(drawType)
{
	
}
GraphicsRenderer::~GraphicsRenderer()
{
	delete _shader;
	delete _vb;
	delete _ibo;
	delete _texture;
	delete _vao;
}

void GraphicsRenderer::render(const glm::mat4& projection, const glm::mat4& view)
{
	_shader->useProgram();
	//_shader->setUniformMat4("u_Projection", 1, GL_FALSE, glm::value_ptr(projection));
	//_shader->setUniformMat4("u_View", 1, GL_FALSE, glm::value_ptr(view));
	_shader->setUniformMat4("u_Model", 1, GL_FALSE, glm::value_ptr(_transform->getTransformMatrix()));
	_vao->bind();
	_ibo->bind();
	_texture->bind();
	glDrawElements(GL_TRIANGLES, _object.indiciesCount, GL_UNSIGNED_INT, nullptr);
	_ibo->unbind();
	_vao->unbind();
	_texture->unbind();
}

void GraphicsRenderer::setColor(const glm::vec4& color)
{
	_color = color;
}

void GraphicsRenderer::setTexture(const std::string& textureFile)
{
	delete _texture;
	_texture = new Texture(textureFile);
}

void GraphicsRenderer::setShader(const std::string& shaderFile)
{
	delete _shader;
	_shader = new Shader(shaderFile);
}

void GraphicsRenderer::instantiate()
{
	createQuad(_transform);
	_vao = new VertexArray();
	_vb = new VertexBuffer(_object.Vertices, 6, _drawType, _object.Layout);
	_ibo = new IndexBuffer(_object.indices, _object.indiciesCount);
	_vao->addBuffer(*_vb);
}

void GraphicsRenderer::setTransform(Transform* transform)
{
	_transform = transform;
}

Transform* GraphicsRenderer::getTransform()
{
	return _transform;
}


