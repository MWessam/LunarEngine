#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/VertexBufferLayout.h"
#include "Transform.h"
#include <glm/gtc/type_ptr.hpp>
const glm::vec4 DEFAULTCOLOR = { 1.0f, 1.0f, 1.0f, 1.0f };
const float DEFAULTTEXINDEX = 0;
const int DEFAULTENTITYID = 0;
const std::string DEFAULTSHADER = "D:/SwE/C#/LunarEngine/LunarEngine/Graphics/ShaderSource/Default.shader";

struct QuadVertex		// Rectangle/square on which we will render our sprite on
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
		Vertices[0].Position = {-1.0f, -1.0f, 0.0f, 1.0f};
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
class GraphicsRenderer		// TODO: implement a way to store my vao vbo ibo and shader and have it all encapsulated This will handle all the rendering of this specific game object.
{
private:
	QuadVertex _object;
	glm::mat4 _mvpMatrix;
	void createQuad(Transform* transform);
	void computeMVP(const glm::mat4& projection, const glm::mat4& view);
	GLenum _drawType;
protected:
	Shader* _shader;
	Texture* _texture;
	Transform* _transform;
	glm::vec4 _color;
	VertexBuffer* _vb;
	VertexArray* _vao;
	IndexBuffer* _ibo;
	GLsizei _indicesCount;
public:
	GraphicsRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color, GLenum drawType);
	GraphicsRenderer(const std::string& textureFile, GLenum drawType);
	GraphicsRenderer(GLenum drawType);
	virtual ~GraphicsRenderer();
	virtual void render(const glm::mat4& projection, const glm::mat4& view);	//TODO: Fix this, it doesn't want to render to the screen whatsoever. I am not sure what went wrong
	void setColor(const glm::vec4& color);
	void setTexture(const std::string& textureFile);
	void setShader(const std::string& shaderFile);
	void instantiate();
	void setTransform(Transform* transform);
	Transform* getTransform();
};

