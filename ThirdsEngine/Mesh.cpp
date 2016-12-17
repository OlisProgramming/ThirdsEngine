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

		void Mesh::render(Camera& cam, GLuint matMVPID) {
			glUniformMatrix4fv(matMVPID, 1, GL_FALSE, &Mat4ModelViewProject(modelMatrix, cam.getView(), cam.getProject())[0][0]);
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			printf("");
			glVertexAttribPointer(
				1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				2,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)(3*sizeof(GLfloat))  // array buffer offset
			);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

			// Draw the triangles !
			glDrawElements(
				GL_TRIANGLES,      // mode
				3*tris,            // count
				GL_UNSIGNED_SHORT, // type
				(void*)0           // element array buffer offset
			);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
		}
	}
}