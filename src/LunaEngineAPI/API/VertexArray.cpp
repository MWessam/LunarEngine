#include "LunaEngineAPI/VertexArray.h"

void GeneralAPIs::VertexArray::addVertexBuffer(std::unique_ptr<VertexBuffer>& vb)
{
	_buffers.push_back(std::move(vb));
}

void GeneralAPIs::VertexArray::setIndexBuffer(std::unique_ptr<IndexBuffer>& ib)
{
	_indexBuffer.release();
	_indexBuffer.reset(ib.release());
}
