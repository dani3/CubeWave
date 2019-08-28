#pragma once

#include "glm/glm.hpp"

class Cube 
{
public:
	Cube(glm::vec3 origin, float length);
	~Cube();

	inline float* GetVertices() const { return m_Vertices; }
	inline unsigned int GetCount() const { return m_Count; }
	inline unsigned int GetSize() const { return m_Size; }

private:
	glm::vec3 m_Origin;

	float m_Length;

	float* m_Vertices;

	unsigned int m_Count;
	unsigned int m_Size;
};
