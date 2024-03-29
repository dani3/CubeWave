#include "Renderer.h"

#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << "): " << function <<
			" " << file << ":" << line << std::endl;

		return false;
	}

	return true;
}

void Renderer::Clear() const
{
	GLCall(glClearColor(0.8f, 0.8f, 0.8f, 0.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const unsigned int count, const Shader& shader) const
{
	shader.Bind();
	va.Bind();

	GLCall(glDrawArrays(GL_TRIANGLES, 0, count));
}
