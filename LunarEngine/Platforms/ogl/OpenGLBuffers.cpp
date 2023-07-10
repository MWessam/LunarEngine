#include "OpenGLBuffers.h"

OpenGL::VertexBuffer::~VertexBuffer()
{
	unbind();
	glDeleteBuffers(1, &_id);
}
OpenGL::VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &_id);
	
}
void OpenGL::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}
void OpenGL::VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGL::VertexBuffer::setData(uint64_t dataSizeInBytes)
{
	bind();
	glCall(glBufferData(GL_ARRAY_BUFFER, _size * dataSizeInBytes, _data, GL_STATIC_DRAW));
}

void OpenGL::VertexBuffer::updateData(uint64_t dataSizeInBytes)
{
	glCall(glBufferData(GL_ARRAY_BUFFER, _size * dataSizeInBytes, _data, GL_STATIC_DRAW));
}


/// INDEX BUFFER vvvvvvv
void OpenGL::IndexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}
void OpenGL::IndexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGL::IndexBuffer::setData(uint64_t dataSizeInBytes)
{
	bind();
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, _size * dataSizeInBytes, _data, GL_STATIC_DRAW));
}

void OpenGL::VertexBuffer::updateData(uint64_t dataSizeInBytes)
{
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER , _size * dataSizeInBytes, _data, GL_STATIC_DRAW));
}
