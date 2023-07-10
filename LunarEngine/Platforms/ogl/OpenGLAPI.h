#pragma once
#include "RendererAPI/RendererAPI.h"
#include <glad/glad.h>
#include "Graphics/GLDebug.h"
namespace OpenGL
{
    class OpenGLAPI :
        public RendererAPI
    {
    public:     //Methods
        // Overriden methods
        void initialize() override;
        void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        void setClearColor(const glm::vec4& color) override;
        void clear() override;
        void setLineWidth(float width) override;
        std::unique_ptr<GeneralAPIs::VertexBuffer> createVertexBuffer() override;
        std::unique_ptr<GeneralAPIs::IndexBuffer> createIndexBuffer() override;
        std::unique_ptr<GeneralAPIs::VertexArray> createVAO() override;
    };
}

