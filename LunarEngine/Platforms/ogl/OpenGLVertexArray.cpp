#include "OpenGLVertexArray.h"
#include <math.h>

OpenGL::OpenGLVertexArray::~OpenGLVertexArray()
{
	unbind();
	glDeleteVertexArrays(1, &_id);
}

OpenGL::OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &_id);
}

void OpenGL::OpenGLVertexArray::addVertexBuffer(const std::unique_ptr<GeneralAPIs::VertexBuffer>& vb)
{
	const GeneralAPIs::BufferLayout& layout = vb->getLayout();

	for (const auto& element : layout.getElements())
	{
		switch (element.Type)
		{
			case GeneralAPIs::ShaderDataType::Float:
			case GeneralAPIs::ShaderDataType::Vec3:
			case GeneralAPIs::ShaderDataType::Vec4:
			{	
				glEnableVertexAttribArray(_vertexBufferIndex);
				glCall(glVertexAttribPointer(_vertexBufferIndex, element.Count, GL_FLOAT, GL_FALSE, layout.getStride(), (void*)element.Offset));
				++_vertexBufferIndex;
				break;
			}
			case GeneralAPIs::ShaderDataType::Mat3:
			case GeneralAPIs::ShaderDataType::Mat4:
			{
				uint8_t count = sqrt(element.SizeInBytes / 4);		// Since matrices are by default floats (4 bytes), and theyre always a square matrix, then we can easily calculate how many elements per row.
				
				for (uint8_t i = 0; i < count; i++)
				{
					glEnableVertexAttribArray(_vertexBufferIndex);
					glVertexAttribPointer(_vertexBufferIndex, count, GL_FLOAT, GL_FALSE, layout.getStride(), (const void*)(element.Offset + sizeof(float) * count * i));
					glVertexAttribDivisor(_vertexBufferIndex, 1);
					++_vertexBufferIndex;
				}
			}
		}
	}
	GeneralAPIs::VertexArray::addVertexBuffer(vb);
}

void OpenGL::OpenGLVertexArray::setIndexBuffer(std::unique_ptr<GeneralAPIs::IndexBuffer>& ib)
{
	bind();
	ib->bind();
	_indexBuffer.reset(ib.release());
}

void OpenGL::OpenGLVertexArray::bind()
{
	glBindVertexArray(_id);
}

void OpenGL::OpenGLVertexArray::unbind()
{
	glCall(glBindVertexArray(0));
}
