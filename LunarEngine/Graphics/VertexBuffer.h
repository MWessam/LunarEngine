#pragma once
#include "GLDebug.h"
class VertexBuffer
{
private:
	GLuint _id;
	GLsizei _size;	// Number of vertices
public:
	VertexBuffer(const GLfloat* vertices, GLsizei size, GLenum drawType);
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;

};

