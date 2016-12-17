#include "PhongShader.h"

namespace te {
	namespace render {

		PhongShader::PhongShader() :
			Shader("phong_vert.glsl", "phong_frag.glsl"),
			idLightAmbient(getUniformID("lightAmbient")) {
			setLightAmbient(Vec3(1.0, 0.0, 1.0));
		}
	}
}