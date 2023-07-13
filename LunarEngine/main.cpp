#include "RendererAPI/RendererAPI.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Graphics/GLDebug.h"
int main()
{
	API api = API::OpenGL;
	std::unique_ptr<RendererAPI> renderer = RendererAPI::create(api);
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


	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 600, "test", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();

	std::unique_ptr<GeneralAPIs::VertexBuffer> vb(std::move(renderer->createVertexBuffer()));
	vb->createBuffer<float>(8, vertices);
	vb->getLayout().push<float>(2, GeneralAPIs::ShaderDataType::Vec2);
	std::unique_ptr<GeneralAPIs::IndexBuffer> ib(std::move(renderer->createIndexBuffer().release()));
	ib->createBuffer(6, indices);

	std::unique_ptr<GeneralAPIs::Shaders> shader(std::move(renderer->createShader()));
	shader->initializeShader("Graphics/ShaderSource/Default.shader");
	renderer->setClearColor({ 0.1f, 0.4f, 0.2f , 1.0f });
	std::unique_ptr<GeneralAPIs::VertexArray> vao(std::move(renderer->createVAO()));
	vao->bind();
	vao->addVertexBuffer(vb); 
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen
		renderer->clear();
		// Use the shader program
		shader->bind();
		vao->bind();
		ib->bind();

		// Draw the triangle
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap the front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;


}