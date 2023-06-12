#include "IndexBuffer.h"

// constructor that takes an array of indices and creates a buffer
IndexBuffer::IndexBuffer(const GLuint* indices, GLsizei size) {
	_size = size;
	glGenBuffers(1, &_id); // generate a buffer name
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); // bind the buffer to GL_ELEMENT_ARRAY_BUFFER target
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, GL_STATIC_DRAW); // allocate and fill the buffer
}

// destructor that deletes the buffer
IndexBuffer::~IndexBuffer() {
	unbind(); // unbind the buffer
	glDeleteBuffers(1, &_id); // delete the buffer name
}

// method that binds the buffer to GL_ELEMENT_ARRAY_BUFFER target
void IndexBuffer::bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); // bind the buffer
}

// method that unbinds the buffer from GL_ELEMENT_ARRAY_BUFFER target
void IndexBuffer::unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // bind a null buffer
}

// method that returns the number of indices
GLsizei IndexBuffer::getSize() const {
	return _size;
}