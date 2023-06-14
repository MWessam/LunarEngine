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
const std::string DEFAULTSHADER = "Graphics/ShaderSource/Default.shader";

struct QuadVertex		// Rectangle/square on which we will render our sprite on
{
	glm::vec4 Positions[4];
	glm::vec4 Color = DEFAULTCOLOR;
	glm::vec2 TexCoord[4];
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
		Positions[0] = { -0.5f, -0.5f, -1.0f, 1.0f};
		Positions[1] = { 0.5f, -0.5f, 0.7f, 1.0f};
		Positions[2] = { 0.5f,  0.5f, -0.3f, 1.0f};
		Positions[3] = { -0.5f,  0.5f, 0.0f, 1.0f};
		Layout.Push<float>(4);
	}
};
class GraphicsRenderer		// TODO: implement a way to store my vao vbo ibo and shader and have it all encapsulated This will handle all the rendering of this specific game object.
{
private:
	QuadVertex _object;
	void createQuad(Transform* transform);
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


};

