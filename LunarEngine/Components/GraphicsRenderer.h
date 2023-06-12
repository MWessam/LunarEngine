#pragma once
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/VertexBufferLayout.h"
#include "Transform.h"

struct QuadVertex		// Rectangle/square on which we will render our sprite on
{
	glm::vec4 Positions[4];
	glm::vec4 Color;
	glm::vec4 TexCoord[4];
	float TexIndex;
	// Editor-only
	int EntityID;
	QuadVertex() 
	{
		Positions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
		Positions[1] = { 0.5f, -0.5f, 0.0f, 1.0f };
		Positions[2] = { 0.5f,  0.5f, 0.0f, 1.0f };
		Positions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };
	}
};
class GraphicsRenderer		// TODO: implement a way to store my vao vbo ibo and shader and have it all encapsulated
{
private:
	QuadVertex _object;
	void createQuad(Transform* transform, int entityID);
protected:
	Shader* _shader;
	Texture* _texture;
	glm::vec4 _color;
	VertexArray* _vao;
	IndexBuffer* _ibo;
	GLsizei _indicesCount;
public:
	GraphicsRenderer(const std::string& shaderFile, const std::string& textureFile,glm::vec4 color);
	virtual ~GraphicsRenderer();
	virtual void render(const glm::mat4& projection, const glm::mat4& view, const Transform& transform) = 0;
	void setColor(const glm::vec4& color);
};

