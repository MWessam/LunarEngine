#pragma once
#include "Buffers.h"
#include "OpenGLAPI.h"

namespace OpenGL
{
	// Will need to refactor this some time, they both share similar functionality but I can't Exactly group them together yet.
	class VertexBuffer
		: public GeneralAPIs::VertexBuffer
	{
	public:		// Methods
		VertexBuffer();
		~VertexBuffer() override;
		void bind() const override;
		void unbind() const override;
		void setData(uint64_t dataSizeInBytes) override;
		void updateData(uint64_t dataSizeInBytes);
	private:	// Members
		GLuint _id;
	};

	class IndexBuffer
		: public GeneralAPIs::IndexBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer() override;
		void bind() const override;
		void unbind() const override;
		void setData(uint64_t dataSizeInBytes) override;
		void updateData(uint64_t dataSizeInBytes);
	private:
		GLuint _id;
	};
}
