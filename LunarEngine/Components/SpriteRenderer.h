#pragma once
#include "GraphicsRenderer.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/VertexBufferLayout.h"

class SpriteRenderer :
    public GraphicsRenderer
{
private:
    VertexBuffer* _vbo;
    VertexArray* _vao;
    IndexBuffer* _ibo;
    VertexBufferLayout* _layout;
    GLsizei _indicesCount;
public:


};

