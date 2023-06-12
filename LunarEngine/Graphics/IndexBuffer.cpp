#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const GLuint* indices, GLsizei size) 
	:_size(size)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	glCall(glGenBuffers(1, &_id));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
	unbind();
	glCall(glDeleteBuffers(1, &_id));
}

void IndexBuffer::bind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
}

void IndexBuffer::unbind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

// method that returns the number of indices
GLsizei IndexBuffer::getSize() const {
	return _size;
}