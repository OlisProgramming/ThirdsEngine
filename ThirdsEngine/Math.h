#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define Mat4Translate(vec3)		glm::translate(vec3)
#define Mat4Scale(vec3)			glm::scale(vec3)
#define Mat4ScaleUniform(s)		glm::scale(te::Vec3(s, s, s))
#define Mat4Rotate(theta, axis)	glm::rotate(theta, axis)
#define Mat4Transform(translate, rotate, scale)		((translate) * (rotate) * (scale))

#define Mat4View(camPos, target, up)				glm::lookAt(camPos, target, up)
#define Mat4Project(fov, aspectRatio, nearZ, farZ)	glm::perspective(fov, aspectRatio, nearZ, farZ)

#define Mat4ModelViewProject(model, view, project)	((project) * (view) * (model))

namespace te {
	typedef glm::vec2 Vec2;
	typedef glm::vec3 Vec3;
	typedef glm::vec4 Vec4;
	typedef glm::mat2 Mat2;
	typedef glm::mat3 Mat3;
	typedef glm::mat4 Mat4;
}