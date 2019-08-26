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

	// Projection matrix
	glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 800.0f, -800.0f, 800.0f);
	
	// View matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::rotate(view, glm::radians(5.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	
	// Model matrix
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0, 0, 0));

	Shader* shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
	shader->SetUniformMat4f("u_Model", model);
	shader->SetUniformMat4f("u_View", view);
	shader->SetUniformMat4f("u_Projection", proj);
	shader->SetUniform4f("u_Color", .2f, .2f, .5f, 1.0f);

	va->Unbind();
	vb->Unbind();
	ib->Unbind();
	shader->Unbind();

	Renderer* renderer = new Renderer();

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer->Clear();

		renderer->Draw(*va, *ib, *shader);	

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
