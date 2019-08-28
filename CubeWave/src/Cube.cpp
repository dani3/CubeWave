#include "Cube.h"

Cube::Cube(glm::vec3 origin, float length)
	: m_Origin(origin), m_Length(length)
{
	float halfLength = m_Length / 2;

	float vertices[] = {
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f,  0.0f, -1.0f,

		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f,  0.0f, 1.0f,

		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength, -1.0f,  0.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength, -1.0f,  0.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength, -1.0f,  0.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength, -1.0f,  0.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength, -1.0f,  0.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength, -1.0f,  0.0f,  0.0f,

		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  1.0f,  0.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  1.0f,  0.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  1.0f,  0.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  1.0f,  0.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  1.0f,  0.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  1.0f,  0.0f,  0.0f,

		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f, -1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f, -1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f, -1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f, -1.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z + halfLength,  0.0f, -1.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y - halfLength, m_Origin.z - halfLength,  0.0f, -1.0f,  0.0f,

		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  1.0f,  0.0f,
		m_Origin.x + halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  1.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z + halfLength,  0.0f,  1.0f,  0.0f,
		m_Origin.x - halfLength, m_Origin.y + halfLength, m_Origin.z - halfLength,  0.0f,  1.0f,  0.0f
	};

	m_Count = 36;
	m_Size = sizeof(vertices);

	m_Vertices = new float[m_Count * 6];
	for (int i = 0; i < m_Count * 6; ++i)
	{
		m_Vertices[i] = vertices[i];
	}
}

Cube::~Cube()
{

}
