#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Cube.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main(void)
{
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(800, 800, "CubeWave", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error initializing GLEW" << std::endl;
		return 0;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	Cube cube(glm::vec3(400.0f, 400.0f, -400.0f), 50.f, 50.f);

	float* positions = cube.GetVertices();

	unsigned int* indices = cube.GetIndices();

	VertexArray* va = new VertexArray();
	VertexBuffer* vb = new VertexBuffer(positions, 24 * sizeof(float));
	VertexBufferLayout* layout = new VertexBufferLayout();
	layout->Push<float>(3);
	va->AddBuffer(*vb, *layout);
	
	IndexBuffer* ib = new IndexBuffer(indices, 36);

	// Specify the bounds of the window to set the correct aspect ratio (1:1)
	glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 800.0f, -800.0f, 800.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	glm::mat4 mvp = proj * view * model;

	Shader* shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
	shader->SetUniformMat4f("u_MVP", mvp);

	va->Unbind();
	vb->Unbind();
	ib->Unbind();
	shader->Unbind();

	Renderer* renderer = new Renderer();

	float r = 0.0f;
	float increment = 0.05f;
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer->Clear();

		shader->Bind();
		shader->SetUniform4f("u_Color", r, .2f, .5f, 1.0f);

		renderer->Draw(*va, *ib, *shader);

		if (r > 1.0f)
		{
			increment = -.05f;
		}
		else if (r < 0.0f)
		{
			increment = .05f;
		}

		r += increment;		

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	delete vb;
	delete ib;
	delete layout;
	delete shader;
	delete renderer;

	glfwTerminate();
	return 0;
}
