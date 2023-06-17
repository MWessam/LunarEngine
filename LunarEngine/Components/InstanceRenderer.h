#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Instance.h"
#include <glm/gtc/type_ptr.hpp>
const glm::vec4 DEFAULTCOLOR = { 1.0f, 1.0f, 1.0f, 1.0f };
const float DEFAULTTEXINDEX = 0;
const int DEFAULTENTITYID = 0;
const std::string DEFAULTSHADER = "D:/SwE/C#/LunarEngine/LunarEngine/Graphics/ShaderSource/Default.shader";
const unsigned int MAX_INSTANCES = 1024;


struct Shape
{
	GLsizei VertexCount;
};
struct QuadVertex : Shape
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
		VertexCount = 4;
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
		Layout.Push<float>(4);
		Layout.Push<float>(4);
		Layout.Push<float>(4);
		Layout.Push<float>(4);

	}
};

class InstanceRenderer
{
private:
	std::unordered_map<Instance*, bool> _instances;
	QuadVertex _object;
	Shader _shader;
	Texture _texture;
	glm::vec4 _color;
	VertexBuffer _vb;
	VertexBuffer _instanceVB;
	VertexArray _vao;
	IndexBuffer* _ibo;
	GLsizei _indicesCount;
	GLenum _drawType;
	glm::mat4 _mvpMat;
	void init();
	void createQuad();
	inline bool canRender();
	bool fustumCullingCheck();
	inline int createInstanceVBO();
	inline void computeMVP(const glm::mat4& view, const glm::mat4& projection);
public:
	InstanceRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color, GLenum drawType);
	InstanceRenderer(const std::string& textureFile, GLenum drawType);
	InstanceRenderer(GLenum drawType);
	~InstanceRenderer() = default;
	void render(const glm::mat4& view, const glm::mat4& projection);
	void addInstance(Instance* instance);
};

