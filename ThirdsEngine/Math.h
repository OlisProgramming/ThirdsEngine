#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define Mat4Translate(x, y, z)	glm::translate(x, y, z)
#define Mat4Scale(x, y, z)		glm::scale(x, y, z)
#define Mat4ScaleUniform(s)		glm::scale(s, s, s)
#define Mat4Rotate(theta, axis)	glm::rotate(theta, axis)

#define Mat4Transform(translate, rotate, scale)		((translate) * (rotate) * (scale))

namespace te {
	typedef glm::vec2 Vec2;
	typedef glm::vec3 Vec3;
	typedef glm::vec4 Vec4;
	typedef glm::mat2 Mat2;
	typedef glm::mat3 Mat3;
	typedef glm::mat4 Mat4;
}