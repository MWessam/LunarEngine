#pragma once
#include "RendererAPI/RendererAPI.h"
class OpenGLAPI :
    public RendererAPI
{
    void initialize() override;
    void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
    void setClearColor(const glm::vec4& color) override;
    void clear() override;
    void setLineWidth(float width) override;
};

