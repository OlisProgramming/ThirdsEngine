#include "Mesh.h"

#include <stdio.h>

namespace te {
	namespace render {

		Mesh::Mesh() :
			vbo(0), ibo(0), modelMatrix(Mat4Identity()) {}

		Mesh::~Mesh() {
		}

		void Mesh::setVertices(std::vector<GLfloat>* vertices, std::vector<unsigned short>* indices) {

			vbo = 0;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(GLfloat), &(*vertices)[0], GL_STATIC_DRAW);

			ibo = 0;
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(unsigned short), &(*indices)[0], GL_STATIC_DRAW);

			tris = indices->size();
		}
	}
}