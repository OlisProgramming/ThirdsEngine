#pragma once

#include <vector>

#include <GL/glew.h>

#include "Camera.h"
#include "Math.h"

namespace te {
	namespace render {

		class Mesh {
		public:
			Mesh();
			~Mesh();
			void setVertices(std::vector<GLfloat>* vertices, std::vector<unsigned short>* indices);
			void render(Camera& cam, GLuint matMVPID);

		private:
			GLuint vbo, ibo;
			Mat4 modelMatrix;
		};
	}
}