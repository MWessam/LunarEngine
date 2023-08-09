#pragma once
#include "glm/glm.hpp"
#include "RendererAPI/GeneralAPIStuff/Buffers.h"
#include "RendererAPI/GeneralAPIStuff/VertexArray.h"
#include "RendererAPI/GeneralAPIStuff/Shaders.h"
#include "RendererAPI/GeneralAPIStuff/Context.h"
#include "RendererAPI/GeneralAPIStuff/Window.h"
#include <memory>

namespace GeneralAPIs
{
	enum class API
	{
		None,
		OpenGL,
		DirectX11,
		DriectX12,
		Vulkan
	};
	class RendererAPI
	{
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
		virtual std::unique_ptr<GeneralAPIs::Shaders> createShader() = 0;
		virtual std::unique_ptr<GeneralAPIs::Context> createContext() = 0;
		virtual std::unique_ptr<GeneralAPIs::Window> createWindow(int width, int height, const std::string& title, std::unique_ptr<GeneralAPIs::Context> context) = 0;

		// Static methods
		static std::unique_ptr<RendererAPI> create(API api);
		inline static const API getAPI() { return s_API; }

	protected:	// Methods

	private:	// Members
		static API s_API;
	};
}


