#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

namespace te {
	namespace render {

		class RenderEngine {
		
		public:
			RenderEngine();

			inline void setShader(Shader* shader) { this->shader = shader; }
			void bindShader();

			void renderMesh(Mesh& mesh, const Camera& cam) const;

		private:
			Shader* shader;
		};
	}
}