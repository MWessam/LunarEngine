#include "VertexArray.h"
#include "GLDebug.h"
#include "VertexBuffer.h"


VertexArray::VertexArray()
{
    glCall(glGenVertexArrays(1, &_id));
    glCall(glBindVertexArray(_id));
}

VertexArray::~VertexArray()
{
    unbind();
    glCall(glDeleteVertexArrays(1, &_id));
}


void VertexArray::addBuffer(const VertexBuffer& vb)
{
    bind();
    vb.bind();
    const std::vector<VertexBufferElement> elements = vb.getLayout().GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const VertexBufferElement element = elements[i];
        glCall(glEnableVertexAttribArray(i));
        glCall(glVertexAttribPointer(i, element.Count, element.Type, element.Normalized,
            vb.getLayout().GetStride(), (void*)offset));
        offset += element.Count * VertexBufferElement::GetSizeOfType(element.Type);
    }
}

void VertexArray::bind() const
{
    glCall(glBindVertexArray(_id));
}

void VertexArray::unbind() const
{
    glCall(glBindVertexArray(0));
}

