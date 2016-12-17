#pragma once

#include "Shader.h"

namespace te {
	namespace render {

		class PhongShader :
			public Shader {

		public:
			PhongShader();

			inline void setLightAmbient(const Vec3& light) { setUniform(idLightAmbient, light); }

		private:
			GLuint idLightAmbient;
		};
	}
}