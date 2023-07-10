#pragma once
#include "Buffers.h"
#include <memory>
namespace GeneralAPIs
{
	class VertexArray
	{
	public:		//Methods
		virtual ~VertexArray() = default;
		virtual void bind() = 0;
		virtual void unbind() = 0;
		virtual void addVertexBuffer(const std::unique_ptr<GeneralAPIs::VertexBuffer>& vb);
		virtual void setIndexBuffer(std::unique_ptr<GeneralAPIs::IndexBuffer>& ib);

	protected:	// Members
		std::vector<std::unique_ptr<GeneralAPIs::VertexBuffer>> _buffers;
		std::unique_ptr<GeneralAPIs::IndexBuffer> _indexBuffer;
	};
}

