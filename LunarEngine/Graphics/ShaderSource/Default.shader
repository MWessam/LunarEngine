#shader vertex
#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in mat4 instanceTransform;
out vec4 vCol;
out vec2 v_TexCoord;
uniform mat4 u_ViewProjection;
void main()
{
	gl_Position = u_ViewProjection * instanceTransform * position;
	v_TexCoord = vec2(texCoord);

}

#shader fragment
#version 460 core
in vec4 vCol;
out vec4 color;
uniform sampler2D u_Texture;
uniform vec4 u_Color;
in vec2 v_TexCoord;

void main() {
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
}