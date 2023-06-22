#pragma once
#include "GLDebug.h"
class IndexBuffer
{
private:
	GLuint _id; 
	GLsizei _size; // the number of indices
public:
	//Constructors and destructor
	IndexBuffer(const GLuint* indices, GLsizei size);
	IndexBuffer() = default;
	~IndexBuffer();

	//Bind to operate on
	void bind() const;

	//Unbind to not modify it any further
	void unbind() const;

	//Getters
	GLsizei getSize() const;
};

