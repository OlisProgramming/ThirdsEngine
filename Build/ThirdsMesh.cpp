#include "ThirdsMesh.h"

ThirdsMesh::ThirdsMesh()
{
	GLuint i;
	//glGenBuffers(1, &i);
	size = 0;
}

ThirdsMesh::~ThirdsMesh()
{
}

void ThirdsMesh::addVertices(ThirdsVertex vertices[])
{
	size = sizeof vertices / 4;  // 4 bytes because floating point precision
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
}

void ThirdsMesh::update()
{
}

void ThirdsMesh::render()
{
	//glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof ThirdsVertex, 0);
	//glDrawArrays(GL_TRIANGLES, 0, size / sizeof ThirdsVertex);

	//glDisableVertexAttribArray(0);
}