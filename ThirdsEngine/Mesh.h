#pragma once

#include <GL/glew.h>

#include "Vertex.h"

namespace te {
	namespace render {

		class Mesh {
		public:
			Mesh();
			~Mesh();
			void setVertices(Vertex vertices[]);
			void render();

		private:
			GLuint vbo;
		};
	}
}