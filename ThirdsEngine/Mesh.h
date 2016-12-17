#pragma once

#include <GL/glew.h>

#include "Camera.h"
#include "Vertex.h"
#include "Math.h"

namespace te {
	namespace render {

		class Mesh {
		public:
			Mesh();
			~Mesh();
			void setVertices(Vertex vertices[]);
			void render(Camera& cam, GLuint matMVPID);

		private:
			GLuint vbo;
			Mat4 modelMatrix;
		};
	}
}