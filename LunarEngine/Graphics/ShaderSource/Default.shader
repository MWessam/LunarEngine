#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
out vec4 vCol;
out vec2 v_TexCoord;
uniform mat4 u_Model;
uniform mat4 u_Projection;
uniform mat4 u_View;
void main()
{
	gl_Position = /*u_Projection * u_View */ u_Model * position;
	v_TexCoord = vec2(texCoord);

}

#shader fragment
#version 330 core
in vec4 vCol;
out vec4 color;
uniform sampler2D u_Texture;
uniform vec4 u_Color;
in vec2 v_TexCoord;

void main() {
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
}