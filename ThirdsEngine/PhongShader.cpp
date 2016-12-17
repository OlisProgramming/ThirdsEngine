#include "PhongShader.h"

namespace te {
	namespace render {

		PhongShader::PhongShader() :
			Shader("phong_vert.glsl", "phong_frag.glsl") {}
	}
}