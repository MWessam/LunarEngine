#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/VertexBufferLayout.h"
#include "Components/Transform.h"
#include <glm/gtc/type_ptr.hpp>
const glm::vec4 DEFAULTCOLOR = { 1.0f, 1.0f, 1.0f, 1.0f };
const float DEFAULTTEXINDEX = 0;
const int DEFAULTENTITYID = 0;
const std::string DEFAULTSHADER = "D:/SwE/C#/LunarEngine/LunarEngine/Graphics/ShaderSource/Default.shader";

//for mesh and sprite renderers.
struct QuadVertex
{
	Vertex Vertices[4];
	glm::vec4 Color = DEFAULTCOLOR;
	VertexBufferLayout Layout;
	GLuint indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
	GLsizei indiciesCount = 6;
	float TexIndex = DEFAULTTEXINDEX;

	// Editor-only
	int EntityID = DEFAULTENTITYID;
	QuadVertex()
	{
		Vertices[0].Position = { -1.0f, -1.0f, 0.0f, 1.0f };
		Vertices[0].TexCoord = { 0.0f, 0.0f };
		Vertices[1].Position = { 1.0f, -1.0f, 0.0f, 1.0f };
		Vertices[1].TexCoord = { 1.0f, 0.0f };
		Vertices[2].Position = { 1.0f,  1.0f, 0.0f, 1.0f };
		Vertices[2].TexCoord = { 1.0f, 1.0f };
		Vertices[3].Position = { -1.0f,  1.0f, 0.0f, 1.0f };
		Vertices[3].TexCoord = { 0.0f, 1.0f };
		Layout.Push<float>(4);
		Layout.Push<float>(2);
	}
};
class InstanceRenderer
{
public:
	void addTransform(Transform* transform);
	void setColor(const glm::vec4& color);
	void setTexture(const std::string& textureFile);
	void setShader(const std::string& shaderFile);
	void draw(const glm::mat4& viewProjection);
	InstanceRenderer(GLenum drawType);
	~InstanceRenderer();
	InstanceRenderer() = default;
	// Use only when you first create a gameObject or any object that might inherit from this class
	void instantiate();
private:
	std::vector<Transform*> _instancesTransforms;
	uint32_t _amountToInstantiate;
	QuadVertex _object;
	GLenum _drawType;
	std::unique_ptr<Shader> _shader;
	std::unique_ptr<Texture> _texture;
	glm::vec4 _color;
	std::unique_ptr<VertexBuffer> _vb;
	std::unique_ptr<VertexBuffer> _instanceBuffer;
	std::unique_ptr<VertexArray> _vao;
	std::unique_ptr<IndexBuffer> _ibo;
	GLsizei _indicesCount;


	void createQuad();
	void createInstanceBuffer();

	void checkRenderableObjects();
};

