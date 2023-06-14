#pragma once
#include "GLDebug.h"
class IndexBuffer
{
private:
	GLuint _id; 
	GLsizei _size; // the number of indices
public:
	IndexBuffer(const GLuint* indices, GLsizei size);
	IndexBuffer() = default;
	~IndexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;
};

