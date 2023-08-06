#include "RendererAPI/RendererAPI.h"
#include "RendererAPI/GeneralAPIStuff/Window.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Graphics/GLDebug.h"
int main()
{
	GeneralAPIs::API api = GeneralAPIs::API::OpenGL;
	std::unique_ptr<GeneralAPIs::RendererAPI> renderer = GeneralAPIs::RendererAPI::create(api);
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
	std::unique_ptr<GeneralAPIs::Context> context(renderer->createContext());
	std::unique_ptr<GeneralAPIs::Window> window(renderer->createWindow(800, 600, "Hello", context));
	std::unique_ptr<GeneralAPIs::VertexBuffer> vb(renderer->createVertexBuffer());
	vb->createBuffer<float>(8, vertices);
	vb->getLayout().push<float>(2, GeneralAPIs::ShaderDataType::Vec2);
	std::unique_ptr<GeneralAPIs::IndexBuffer> ib(renderer->createIndexBuffer().release());
	ib->createBuffer(6, indices);
	std::unique_ptr<GeneralAPIs::Shaders> shader(renderer->createShader());
	shader->initializeShader("Graphics/ShaderSource/Default.shader");
	renderer->setClearColor({ 0.1f, 0.4f, 0.2f , 1.0f });
	std::unique_ptr<GeneralAPIs::VertexArray> vao(renderer->createVAO());
	vao->bind();
	vao->addVertexBuffer(vb); 
	while (window->isRendering()) {
		// Clear the screen
		renderer->clear();
		// Use the shader program
		shader->bind();
		vao->bind();
		ib->bind();

		// Draw the triangle
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		window->pollEvents();
		window->swapBuffers();
	}
	return 0;


}