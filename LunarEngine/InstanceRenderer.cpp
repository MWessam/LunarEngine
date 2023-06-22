#include "InstanceRenderer.h"

void InstanceRenderer::addTransform(Transform* transform)
{
	_instancesTransforms.push_back(transform);
}

void InstanceRenderer::setColor(const glm::vec4& color)
{
	_color = color;
}

void InstanceRenderer::setTexture(const std::string& textureFile)
{
	_texture.reset(new Texture(textureFile));
}

void InstanceRenderer::setShader(const std::string& shaderFile)
{
	_shader.reset(new Shader(shaderFile));
}

void InstanceRenderer::draw(const glm::mat4& viewProjection)
{
	checkRenderableObjects();
	std::cout << _amountToInstantiate << std::endl;
	_shader->useProgram();
	_shader->setUniformMat4("u_ViewProjection", 1, GL_FALSE, glm::value_ptr(viewProjection));
	_vao->bind();
	_ibo->bind();
	_vb->bind();
	_instanceBuffer->bind();
	_texture->bind();
	glCall(glDrawElementsInstanced(GL_TRIANGLES, _object.indiciesCount, GL_UNSIGNED_INT, nullptr, _amountToInstantiate));
	_vao->unbind();
	_ibo->unbind();
	_vb->unbind();
	_instanceBuffer->unbind();
	_texture->unbind();
	_shader->unuseProgram();
}

InstanceRenderer::InstanceRenderer(GLenum drawType) :
	_drawType(drawType), _object()
{
}

InstanceRenderer::~InstanceRenderer()
{
}

void InstanceRenderer::instantiate()
{
	createQuad();
	_vb.reset(new VertexBuffer(_object.Vertices, 4, _drawType, _object.Layout));
	createInstanceBuffer();
	_ibo.reset(new IndexBuffer(_object.indices, _object.indiciesCount));
	_vao.reset(new VertexArray());
	_vao->bind();
	_vb->bind();
	_vao->addBuffer(*_vb);
	_instanceBuffer->bind();
	std::size_t vec4Size = sizeof(glm::vec4);
	std::size_t mat4Size = sizeof(glm::mat4);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, mat4Size, nullptr);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, mat4Size, (void*)(1 * vec4Size));
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, mat4Size, (void*)(2 * vec4Size));
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, mat4Size, (void*)(3 * vec4Size));
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
	glVertexAttribDivisor(5, 1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);
	glEnableVertexAttribArray(5);
	_vao->unbind();
}
void InstanceRenderer::createQuad()
{
	constexpr GLsizei vertexCount = 4;
	for (GLsizei i = 0; i < vertexCount; i++)
	{
		_object.Vertices[i].Position = _object.Vertices[i].Position;
	}
	_object.Color = _color;
	_object.TexIndex = 0;
}

void InstanceRenderer::createInstanceBuffer()
{
	_instanceBuffer.reset(new VertexBuffer());
	_instanceBuffer->createBuffer<glm::mat4>(GL_ARRAY_BUFFER, 1, nullptr, GL_DYNAMIC_DRAW);

}

void InstanceRenderer::checkRenderableObjects()
{
	_amountToInstantiate = _instancesTransforms.size();
	std::vector<glm::mat4> availableObjects(_amountToInstantiate);
	for (int i = 0; i < _amountToInstantiate; ++i)
	{
		availableObjects[i] = _instancesTransforms[i]->getTransformMatrix();
	}
	_instanceBuffer->createBuffer<glm::mat4>(GL_ARRAY_BUFFER, _amountToInstantiate,
		availableObjects.data(), GL_STATIC_DRAW);
}
