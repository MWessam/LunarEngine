#pragma once
#include <vector>
#include "GLDebug.h"
struct VertexBufferElement
{
    unsigned int Type;
    unsigned int Count;
    unsigned char Normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
        case GL_FLOAT: return sizeof(GLfloat);
        case GL_UNSIGNED_INT: return sizeof(GLuint);
        case GL_UNSIGNED_BYTE: return sizeof(GLbyte);
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout
{
private:
    unsigned int _stride;
    std::vector<VertexBufferElement> _elements;

public:
    VertexBufferLayout() :
        _stride(0) { }

    inline const std::vector<VertexBufferElement> GetElements() const { return _elements; };
    inline unsigned int GetStride() const { return _stride; };

    template<typename T>
    void Push(unsigned int count)
    {
        static_assert(true);
    }

    template<>
    void Push<float>(unsigned int count)
    {
        _elements.push_back({ GL_FLOAT, count, false });
        _stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    void Push<unsigned int>(unsigned int count)
    {
        _elements.push_back({ GL_UNSIGNED_INT, count, false });
        _stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }
    template<>
    void Push<unsigned char>(unsigned int count)
    {
        _elements.push_back({ GL_UNSIGNED_BYTE, count, true });
        _stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);

    }
};

