#pragma once
#include "GLDebug.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"
class VertexBuffer
{
private:
	GLuint _id;
	GLsizei _size;	// Number of vertices
	VertexBufferLayout _layout;
public:
	VertexBuffer(const glm::vec4* vertices, GLsizei size, GLenum drawType, VertexBufferLayout layout);
	VertexBuffer() = default;
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;
	VertexBufferLayout getLayout() const;

};

