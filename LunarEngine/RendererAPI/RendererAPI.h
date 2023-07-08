#pragma once
#include "glm/glm.hpp"

class RendererAPI
{
public:
	enum class API
	{
		OpenGL,
		DirectX11,
		DriectX12,
		Vulkan
	};

public:
	virtual ~RendererAPI() = default;
	virtual void initialize() = 0;
	virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
	virtual void setClearColor(const glm::vec4& color) = 0;
	virtual void clear() = 0;
	virtual void setLineWidth(float width) = 0;

	static RendererAPI create();
	inline static const API getAPI() { return s_API; }
private:
	static API s_API;
};

