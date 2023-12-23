#pragma once
#include "VertexArray.h"
#include "OpenGLBuffers.h"
#include "OpenGLAPI.h"
namespace OpenGL
{
	class VertexArray:
		public GeneralAPIs::VertexArray
	{
	public:		// Methods
		~VertexArray() override;
		VertexArray();
		void addVertexBuffer(std::unique_ptr<GeneralAPIs::VertexBuffer>& vb) override;
		void setIndexBuffer(std::unique_ptr<GeneralAPIs::IndexBuffer>& ib) override;
		void bind() override;
		void unbind() override;


	private:	// Members
		GLuint _id;
		uint32_t _vertexBufferIndex = 0;
		
	};
}


