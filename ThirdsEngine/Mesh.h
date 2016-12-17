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

			inline Mat4& getModelMatrix() { return modelMatrix; }
			inline GLuint getVbo() { return vbo; }
			inline GLuint getIbo() { return ibo; }
			inline int getTris() { return tris; }

			inline void setTexture(GLuint tex) { this->tex = tex; }
			inline GLuint getTexture() const { return tex; }
			void setVertices(std::vector<GLfloat>* vertices, std::vector<unsigned short>* indices);

		private:
			GLuint vbo, ibo, tex;
			int tris;
			Mat4 modelMatrix;
		};
	}
}