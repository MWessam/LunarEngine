#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const GLfloat* vertices, GLsizei size, GLenum drawType):
	_size(size)
{
	glGenBuffers(1, &_id);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, drawType);
}

VertexBuffer::~VertexBuffer()
{
	unbind();
	glDeleteBuffers(1, &_id);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLsizei VertexBuffer::getSize() const
{
	return _size;
}
