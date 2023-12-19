#include "RendererAPI/RendererAPI.h"
#include "RendererAPI/GeneralAPIStuff/Window.h"
#include "Renderer.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Graphics/GLDebug.h"
int main()
{
	GeneralAPIs::API api = GeneralAPIs::API::OpenGL;
	std::shared_ptr<GeneralAPIs::RendererAPI> rendererApi = GeneralAPIs::RendererAPI::create(api);
	uint32_t indices[] = {
		0, 1, 2,
		2, 3, 0
	};
	float vertices[] =
	{
		-1.0f, -1.0f,
		1.0f, -1.0f,
		1.0f, 1.0f,
		-1.0f, 1.0f
	};
	std::shared_ptr<Renderer::Renderer> renderer = std::make_shared<Renderer::Renderer>(rendererApi);
	renderer->createWindow(800, 600, "Lunar Engine");
	std::unique_ptr<GeneralAPIs::VertexBuffer> vb = rendererApi->createVertexBuffer();
	vb->createBuffer<float>(8, vertices);
	vb->getLayout().push<float>(2, GeneralAPIs::ShaderDataType::Vec2);
	std::unique_ptr<GeneralAPIs::IndexBuffer> ib(rendererApi->createIndexBuffer().release());
	ib->createBuffer(6, indices);
	std::unique_ptr<GeneralAPIs::Shaders> shader(rendererApi->createShader());
	shader->initializeShader("Graphics/ShaderSource/Default.shader");
	rendererApi->setClearColor({ 0.1f, 0.4f, 0.2f , 1.0f });
	std::unique_ptr<GeneralAPIs::VertexArray> vao(rendererApi->createVAO());
	vao->bind();
	vao->addVertexBuffer(vb); 

	while (renderer->render()) {
		// Use the shader program
		shader->bind();
		vao->bind();
		ib->bind();
		// Draw the triangle
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		renderer->updateRenderer();
	}
	return 0;
}