#include "InstanceRenderer.h"

void InstanceRenderer::init()
{
	createQuad();
	_vb.createVB(_object.Vertices, _object.VertexCount, _drawType, _object.Layout);
	_ibo = new IndexBuffer(_object.indices, _object.indiciesCount);
	_vao.addBuffer(_vb);
	_instanceVB.bind();
	VertexBufferLayout instanceLayout;
	instanceLayout.Push<float>(4);
	instanceLayout.Push<float>(4);
	instanceLayout.Push<float>(4);
	instanceLayout.Push<float>(4);

}

inline bool InstanceRenderer::canRender()
{
	return fustumCullingCheck();
}

//Check if object is within camera bounds, if not then don't render.
//Very expensive operation, need to optimize
bool InstanceRenderer::fustumCullingCheck()
{
	// Ugly hack but will fix later dont worry
	for (const Vertex vertex : _object.Vertices)
	{
		glm::vec4 clipSpacePosition = _mvpMat * vertex.Position;
		if (clipSpacePosition.x < -clipSpacePosition.w ||
			clipSpacePosition.x > clipSpacePosition.w ||
			clipSpacePosition.y < -clipSpacePosition.w ||
			clipSpacePosition.y > clipSpacePosition.w ||
			clipSpacePosition.z < -clipSpacePosition.w ||
			clipSpacePosition.z > clipSpacePosition.w)
		{
			return false;
		}
	}
	return true;
}

void InstanceRenderer::createQuad()
{
	for (GLsizei i = 0; i < _object.VertexCount; i++)
	{
		_object.Vertices[i].Position = _object.Vertices[i].Position;
	}
	_object.Color = _color;
	_object.TexIndex = 0;
}

InstanceRenderer::InstanceRenderer(const std::string& shaderFile, const std::string& textureFile, glm::vec4 color, GLenum drawType):
    _object(),
    _shader(shaderFile),
    _texture(textureFile),
    _color(color),
    _vb(),
    _vao(),
	_instanceVB(),
	_drawType(drawType)
{
	init();
}

InstanceRenderer::InstanceRenderer(const std::string& textureFile, GLenum drawType) :
	_object(),
	_shader(DEFAULTSHADER),
	_texture(textureFile),
	_drawType(drawType),
	_vb(),
	_vao(),
	_instanceVB(),
	_color({1.0f,1.0f,1.0f,1.0f})
{
	init();
}

inline void InstanceRenderer::computeMVP(const glm::mat4& view, const glm::mat4& projection)
{
	_mvpMat = projection * view;
}

InstanceRenderer::InstanceRenderer(GLenum drawType):
_object(),
_shader(DEFAULTSHADER),
_texture(),
_drawType(drawType),
_instanceVB()
{
	init();


}

void InstanceRenderer::addInstance(Instance* instance)
{
	_instances[instance] = true;
}

inline int InstanceRenderer::createInstanceVBO()
{
	std::vector<glm::mat4> transforms;
	for (auto const& instance : _instances)
	{
		if(instance.second)
			transforms.push_back(instance.first->TransformData.getTransformMatrix());
	}
	_instanceVB.bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * transforms.size(), &transforms[0], GL_STATIC_DRAW);
	return transforms.size();
}

// Ill need to pass in the vertices and bind to the og vertex buffer, then ill also need to pass in the transform matrices and bind to the instance vb.
void InstanceRenderer::render(const glm::mat4& view, const glm::mat4& projection)
{
	//if (!canRender())
	//{
	//	return;
	//}
	computeMVP(view, projection);
	_shader.useProgram();
	_shader.setUniformMat4("u_ViewProjection", 1, GL_FALSE, glm::value_ptr(_mvpMat));
	_vao.bind();
	_ibo->bind();
	int instanceCount = createInstanceVBO();
	_instanceVB.bind();
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));
	glCall(glVertexAttribDivisor(2, 1));
	glCall(glVertexAttribDivisor(3, 1));
	glCall(glVertexAttribDivisor(4, 1));
	glCall(glVertexAttribDivisor(5, 1));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);
	glEnableVertexAttribArray(5);
	glEnableVertexAttribArray(6);
	glCall(glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instanceCount));
	_vao.unbind();
}
