#pragma once

#include "glm/glm.hpp"

class Cube 
{
public:
	Cube(glm::vec3 origin, float length);
	~Cube();

	void Update(float offset);
	void Draw();

	inline float* GetVertices() const { return m_Vertices; }
	inline unsigned int* GetIndices() const { return m_Indices; }

private:
	glm::vec3 m_Origin;

	float m_Length;

	float* m_Vertices;
	unsigned int* m_Indices;

};
