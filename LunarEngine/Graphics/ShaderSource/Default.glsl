#shader vertex
#version 400 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
out vec4 vCol;
out vec2 v_TexCoord;
uniform mat4 model;
uniform mat4 proj;
void main()
{
	gl_Position = proj * model * vec4(position, 1.0f);
	v_TexCoord = vec2(texCoord.x, texCoord.y);
}

#shader fragment
#version 400 core
in vec4 vCol;
out vec4 color;
uniform sampler2D u_Texture;
in vec2 v_TexCoord;

void main() {
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
}