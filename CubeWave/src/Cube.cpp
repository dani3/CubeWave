#include "Cube.h"

Cube::Cube(glm::vec3 origin, float width, float height)
	: m_Origin(origin), m_Width(width), m_Heigth(height)
{
	float halfWidth = m_Width / 2;
	float halfHeight = m_Heigth / 2;
	
	m_Vertices[0] = m_Origin.x - halfWidth; 
	m_Vertices[1] = m_Origin.y - halfWidth; 
	m_Vertices[2] = m_Origin.z - halfWidth; 

	m_Vertices[3] = m_Origin.x + halfWidth; 
	m_Vertices[4] = m_Origin.y - halfWidth; 
	m_Vertices[5] = m_Origin.z - halfWidth; 

	m_Vertices[6] = m_Origin.x + halfWidth; 
	m_Vertices[7] = m_Origin.y + halfWidth; 
	m_Vertices[8] = m_Origin.z - halfWidth; 

	m_Vertices[9]  = m_Origin.x - halfWidth;
	m_Vertices[10] = m_Origin.y + halfWidth;
	m_Vertices[11] = m_Origin.z - halfWidth;

	m_Vertices[12] = m_Origin.x - halfWidth;
	m_Vertices[13] = m_Origin.y - halfWidth;
	m_Vertices[14] = m_Origin.z + halfWidth;

	m_Vertices[15] = m_Origin.x + halfWidth;
	m_Vertices[16] = m_Origin.y - halfWidth;
	m_Vertices[17] = m_Origin.z + halfWidth;

	m_Vertices[18] = m_Origin.x + halfWidth;
	m_Vertices[19] = m_Origin.y + halfWidth;
	m_Vertices[20] = m_Origin.z + halfWidth;

	m_Vertices[21] = m_Origin.x - halfWidth;
	m_Vertices[22] = m_Origin.y + halfWidth;
	m_Vertices[23] = m_Origin.z + halfWidth;

	m_Indices[0] = 0;
	m_Indices[1] = 2;
	m_Indices[2] = 1;

	m_Indices[3] = 0;
	m_Indices[4] = 3;
	m_Indices[5] = 2;

	m_Indices[6] = 1;
	m_Indices[7] = 2;
	m_Indices[8] = 6;

	m_Indices[9]  = 6;
	m_Indices[10] = 5;
	m_Indices[11] = 1;

	m_Indices[12] = 4;
	m_Indices[13] = 5;
	m_Indices[14] = 6;

	m_Indices[15] = 6;
	m_Indices[16] = 7;
	m_Indices[17] = 4;

	m_Indices[18] = 2;
	m_Indices[19] = 3;
	m_Indices[20] = 6;

	m_Indices[21] = 6;
	m_Indices[22] = 3;
	m_Indices[23] = 7;

	m_Indices[24] = 0;
	m_Indices[25] = 7;
	m_Indices[26] = 3;

	m_Indices[27] = 0;
	m_Indices[28] = 4;
	m_Indices[29] = 7;

	m_Indices[30] = 0;
	m_Indices[31] = 1;
	m_Indices[32] = 5;

	m_Indices[33] = 0;
	m_Indices[34] = 5;
	m_Indices[35] = 4;
}

Cube::~Cube() 
{

}
