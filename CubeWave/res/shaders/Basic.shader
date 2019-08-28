#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec3 v_Normal;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
	v_Normal = normal;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Normal;

uniform vec4 u_Color;

void main()
{
	if (v_Normal == vec3(0.0f, 0.0f, 1.0f))
	{
		color = vec4(0.19f, 0.29f, 0.47f, 0.0f);
	}
	else if (v_Normal == vec3(1.0f, 0.0f, 0.0f))
	{
		color = vec4(0.89f, 0.86f, 0.64f, 0.0f);
	}
	else if (v_Normal == vec3(0.0f, 1.0f, 0.0f))
	{
		color = vec4(0.47f, 0.67f, 0.66f, 0.0f);
	}
	else 
	{
		color = u_Color;
	}
};