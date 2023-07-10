#include "VertexArray.h"

void GeneralAPIs::VertexArray::addVertexBuffer(const std::unique_ptr<VertexBuffer>& vb)
{
	_buffers.push_back(vb);
}

void GeneralAPIs::VertexArray::setIndexBuffer(std::unique_ptr<IndexBuffer>& ib)
{
	_indexBuffer.reset(ib.release());
}
