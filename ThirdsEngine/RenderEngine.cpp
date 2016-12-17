#include "RenderEngine.h"

namespace te {
	namespace render {

		RenderEngine::RenderEngine() {}

		void RenderEngine::renderMesh(Mesh& mesh, const Camera& cam) const {

			shader->setMVP(Mat4ModelViewProject(mesh.getModelMatrix(), cam.getView(), cam.getProject()));

			glBindTexture(GL_TEXTURE_2D, mesh.getTexture());

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, mesh.getVbo());
			glVertexAttribPointer(
				0,                  // attribute 0.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			glVertexAttribPointer(
				1,                  // attribute 1.
				2,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				(3 * sizeof(GLfloat)),  // stride
				(void*)0			// array buffer offset
			);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.getIbo());

			// Draw the triangles !
			glDrawElements(
				GL_TRIANGLES,      // mode
				3 * mesh.getTris(),  // count
				GL_UNSIGNED_SHORT, // type
				(void*)0           // element array buffer offset
			);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
		}
	}
}