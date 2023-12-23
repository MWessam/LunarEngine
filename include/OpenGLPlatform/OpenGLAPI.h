#pragma once
#include "RendererAPI.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GLDebug.h"
namespace OpenGL
{
    class OpenGLAPI :
        public GeneralAPIs::RendererAPI
    {
    public:     //Methods
        void initialize() override;
        void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        void setClearColor(const glm::vec4& color) override;
        void clear() override;
        void setLineWidth(float width) override;
        std::unique_ptr<GeneralAPIs::VertexBuffer> createVertexBuffer() override;
        std::unique_ptr<GeneralAPIs::IndexBuffer> createIndexBuffer() override;
        std::unique_ptr<GeneralAPIs::VertexArray> createVAO() override;
        std::shared_ptr<GeneralAPIs::Shaders> createShader(const std::string& name, const std::string& path) override;
        std::unique_ptr<GeneralAPIs::Context> createContext() override;
        std::shared_ptr<GeneralAPIs::Window> createWindow(int width, int height, const std::string& title, std::unique_ptr<GeneralAPIs::Context> context) override;


    };
}

