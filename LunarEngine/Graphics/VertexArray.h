#pragma once
#include <vector>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class VertexArray
{
private:
	unsigned int _id;

public:
	VertexArray();
	~VertexArray();
	void addBuffer(const VertexBuffer& vb);
	void bind() const;
	void unbind() const;
};
