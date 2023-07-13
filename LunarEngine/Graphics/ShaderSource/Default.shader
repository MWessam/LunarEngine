#shader vertex
#version 330 core
layout(location = 0) in vec2 position;
out vec4 vCol;
uniform mat4 u_ViewProjection;
void main()
{
	gl_Position = vec4(position, 0.0f, 1.0f);
	vCol = vec4(position, 1.0f, 1.0f);
}

#shader fragment
#version 330 core
out vec4 color;
in vec4 vCol;

void main() {
	color = vCol;
}