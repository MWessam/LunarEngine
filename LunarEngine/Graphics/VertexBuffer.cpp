#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const GLfloat* vertices, GLsizei size, GLenum drawType):
	_size(size)
{
	glCall(glGenBuffers(1, &_id));
	bind();
	glCall(glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, drawType));
}

VertexBuffer::~VertexBuffer()
{
	unbind();
	glCall(glDeleteBuffers(1, &_id));
}

void VertexBuffer::bind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
}

void VertexBuffer::unbind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

GLsizei VertexBuffer::getSize() const
{
	return _size;
}
