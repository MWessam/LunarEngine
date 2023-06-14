#pragma once
#include "GLDebug.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"
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
	VertexBuffer() = default;
	~VertexBuffer();
	void bind() const;
	void unbind() const;
	GLsizei getSize() const;
	VertexBufferLayout getLayout() const;

};

