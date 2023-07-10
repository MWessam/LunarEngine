#pragma once
#include "glm/glm.hpp"
#include "RendererAPI/GeneralAPIStuff/Buffers.h"
#include "RendererAPI/GeneralAPIStuff/VertexArray.h"
#include <memory>

class RendererAPI
{
public:		// Enum
	enum class API
	{
		OpenGL,
		DirectX11,
		DriectX12,
		Vulkan
	};

public:		// Methods
	virtual ~RendererAPI() = default;
	// Setup and modify API
	virtual void initialize() = 0;
	virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
	virtual void setClearColor(const glm::vec4& color) = 0;
	virtual void clear() = 0;
	virtual void setLineWidth(float width) = 0;

	//	Create api elements

	virtual std::unique_ptr<GeneralAPIs::VertexBuffer> createVertexBuffer() = 0;
	virtual std::unique_ptr<GeneralAPIs::IndexBuffer> createIndexBuffer() = 0;
	virtual std::unique_ptr<GeneralAPIs::VertexArray> createVAO() = 0;


	// Static methods
	static std::unique_ptr<RendererAPI> create();
	inline static const API getAPI() { return s_API; }

protected:	// Methods

private:	// Members
	static API s_API;
};

