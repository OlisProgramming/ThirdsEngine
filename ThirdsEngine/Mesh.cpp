#include "Mesh.h"

#include <stdio.h>

namespace te {
	namespace render {

		Mesh::Mesh() :
			vbo(0), modelMatrix(Mat4Identity()) {}

		Mesh::~Mesh() {
		}

		void Mesh::setVertices(Vertex vertices[]) {
			GLfloat g_vertex_buffer_data[] = {
				1.0f, -1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f,
				0.0f,  1.0f, 0.0f,
			};

			vbo = 0;
			if (!glGenBuffers) { printf("uh oh"); return; }
			// Generate 1 buffer, put the resulting identifier in vertexbuffer
			glGenBuffers(1, &vbo);
			// The following commands will talk about our 'vertexbuffer' buffer
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			// Give our vertices to OpenGL.
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
		}

		void Mesh::render(Camera& cam, GLuint matMVPID) {
			glUniformMatrix4fv(matMVPID, 1, GL_FALSE, &Mat4ModelViewProject(modelMatrix, cam.getView(), cam.getProject())[0][0]);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
			glDisableVertexAttribArray(0);
		}
	}
}