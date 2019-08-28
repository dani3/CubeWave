#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Cube.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define CUBE_SIZE		22
#define NUM_CUBES		16

float Map(float fromMin, float fromMax, float toMin, float toMax, float value);

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
	window = glfwCreateWindow(968, 968, "CubeWave", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	int monitorX, monitorY;
	glfwGetMonitorPos(monitor, &monitorX, &monitorY);

	int windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	glfwSetWindowPos(window,
		monitorX + (mode->width - windowWidth) / 2,
		monitorY + (mode->height - windowHeight) / 2);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error initializing GLEW" << std::endl;
		return 0;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	glEnable(GL_DEPTH_TEST);

	// Create one cube
	Cube cube(glm::vec3(0.0f, 0.0f, 0.0f), CUBE_SIZE);

	float* vertices    = cube.GetVertices();
	unsigned int count = cube.GetCount();
	unsigned int size  = cube.GetSize();

	VertexArray* va            = new VertexArray();
	VertexBuffer* vb           = new VertexBuffer(vertices, size);
	VertexBufferLayout* layout = new VertexBufferLayout();

	layout->Push<float>(3);
	layout->Push<float>(3);

	va->AddBuffer(*vb, *layout);

	// Projection matrix
	glm::mat4 proj = glm::ortho(-400.0f, 400.0f, -400.0f, 400.0f, -1000.0f, 1000.0f);
	
	// View matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 75.0f, 0.0f));
	view = glm::rotate(view, glm::radians(35.264f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, glm::radians(45.f), glm::vec3(0.0f, -1.0f, 0.0f));
	
	Shader* shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
	shader->SetUniformMat4f("u_View", view);
	shader->SetUniformMat4f("u_Projection", proj);
	shader->SetUniform4f("u_Color", .49f, .6f, .6f, 1.0f);

	va->Unbind();
	vb->Unbind();
	shader->Unbind();

	Renderer* renderer = new Renderer();

	shader->Bind();

	float maxD = glm::distance(glm::vec3((NUM_CUBES / 2) * CUBE_SIZE, 0.f, (NUM_CUBES / 2) * CUBE_SIZE), glm::vec3(0.0f, 0.f, 0.0f));
	float angle = 0;
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer->Clear();

		for (int j = 0; j < NUM_CUBES; ++j)
		{
			for (int i = 0; i < NUM_CUBES; ++i)
			{
				float dist = glm::distance(glm::vec3(i * CUBE_SIZE, 0.0f, j * CUBE_SIZE), glm::vec3(NUM_CUBES * CUBE_SIZE / 2, 0.0f, NUM_CUBES * CUBE_SIZE / 2));
				float offset = Map(0.0f, maxD, -150, 150, dist);	
				float newAngle = angle + offset;
				float scaleFactor = Map(-1.0f, 1.0f, 5, 15, glm::sin(glm::radians(newAngle)));

				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(i * CUBE_SIZE, 50.0f, j * CUBE_SIZE));
				model = glm::scale(model, glm::vec3(1, scaleFactor, 1));

				shader->SetUniformMat4f("u_Model", model);

				renderer->Draw(*va, count, *shader);
			}
		}

		angle -= 3;

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	delete vb;
	delete layout;
	delete shader;
	delete renderer;

	glfwTerminate();

	return 0;
}

static float Map(float fromMin, float fromMax, float toMin, float toMax, float value) 
{
	return toMin + (value - fromMin) * (toMax - toMin) / (fromMax - fromMin);
}
