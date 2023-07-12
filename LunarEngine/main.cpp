#include "RendererAPI/RendererAPI.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Graphics/GLDebug.h"
int main()
{
	API api = API::OpenGL;
	std::unique_ptr<RendererAPI> renderer = RendererAPI::create(api);
	uint64_t indices[] = {
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
	//std::unique_ptr<GeneralAPIs::IndexBuffer> ib(std::move(renderer->createIndexBuffer().release()));
	//ib->createBuffer(6, indices);

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec2 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
		"}\0";
	GLuint vertexShader = (glCreateShader(GL_VERTEX_SHADER));
	glCall(glShaderSource(vertexShader, 1, &vertexShaderSource, NULL));
	glCall(glCompileShader(vertexShader));

	// Create and compile the fragment shader
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
		"}\0";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glCall(glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL));
	glCall(glCompileShader(fragmentShader));

	GLuint shaderProgram = glCreateProgram();
	glCall(glAttachShader(shaderProgram, vertexShader));
	glCall(glAttachShader(shaderProgram, fragmentShader));
	glCall(glLinkProgram(shaderProgram));
	renderer->setClearColor({ 0.1f, 0.4f, 0.2f , 1.0f });
	std::unique_ptr<GeneralAPIs::VertexArray> vao(std::move(renderer->createVAO()));
	vao->bind();
	vao->addVertexBuffer(vb);
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen
		renderer->clear();
		// Use the shader program
		glUseProgram(shaderProgram);
		vao->bind();
		//ib->bind();

		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Swap the front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}
	glCall(glDeleteProgram(shaderProgram));
	glCall(glDeleteShader(fragmentShader));
	glCall(glDeleteShader(vertexShader));
	glfwTerminate();
	return 0;


}