#pragma once
#include "GLDebug.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"
#include <iostream>
struct Vertex
{
	glm::vec4 Position;
	glm::vec2 TexCoord;
};
class VertexBuffer
{
private:
	GLuint _id;
	GLsizei _size;	// Number of vertices
	VertexBufferLayout _layout;
public:
	VertexBuffer(const Vertex* vertices, GLsizei size, GLenum drawType, VertexBufferLayout layout);
	VertexBuffer();
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;
	VertexBufferLayout getLayout() const;
	template <typename T>
	void createBuffer(GLenum target, GLsizei size, T* data, GLenum drawType);

};

template<typename T>
void VertexBuffer::createBuffer(GLenum target, GLsizei size, T* data, GLenum drawType)
{
	_size = size;
	bind();
	glBufferData(target, size * sizeof(T), data, drawType);
}
