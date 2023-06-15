#include "GraphicsRenderer.h"


void printMat(const glm::mat4& matrix) {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void printVec(const glm::vec4& vector)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}
void testMVP(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model, const glm::vec3 vertex) {
	glm::mat4 mvp = proj * view * model;
	printMat(proj);
	printMat(view);
	printMat(model);
	printMat(mvp);
	glm::vec4 result = mvp * glm::vec4(vertex, 1.0f);
	printVec(result);
	glm::vec4 result2 = result / result.w;
	printVec(result2);
}
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
	_shader->setUniformMat4("u_Projection", 1, GL_FALSE, glm::value_ptr(projection));
	_shader->setUniformMat4("u_View", 1, GL_FALSE, glm::value_ptr(view));
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




