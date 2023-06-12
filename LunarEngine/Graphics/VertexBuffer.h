#pragma once
#include "GLDebug.h"
#include "VertexBufferLayout.h"
class VertexBuffer
{
private:
	GLuint _id;
	GLsizei _size;	// Number of vertices
	VertexBufferLayout _layout;
public:
	VertexBuffer(const GLfloat* vertices, GLsizei size, GLenum drawType, VertexBufferLayout layout);
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;
	VertexBufferLayout getLayout() const;

};

