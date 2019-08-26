#pragma once

#include "glm/glm.hpp"

class Cube 
{
public:
	Cube(glm::vec3 origin, float width, float height);
	~Cube();

	inline float* GetVertices() const { return m_Vertices; }
	inline unsigned int* GetIndices() const { return m_Indices; }

private:
	glm::vec3 m_Origin;

	float m_Width;
	float m_Heigth;

	float* m_Vertices = new float[24];
	unsigned int* m_Indices = new unsigned int[36];
};
