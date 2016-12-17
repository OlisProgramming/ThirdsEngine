#pragma once

#include "Math.h"

namespace te {
	namespace render {
		class Camera {
		public:
			Camera(Vec3 pos, Vec3 target, Vec3 up);
			void updateMatrices();

			inline Vec3 getPos() const { return pos; }
			inline void setPos(const Vec3& pos) { this->pos = pos; }

			inline Vec3 getTarget() const { return target; }
			inline void setTarget(const Vec3& target) { this->target = target; }

			inline Vec3 getUp() const { return up; }
			inline void setUp(const Vec3& up) { this->up = up; }

			inline Mat4 getView() const { return viewMatrix; }
			inline Mat4 getProject() const { return projMatrix; }

		private:
			Vec3 pos;
			Vec3 target;
			Vec3 up;
			Mat4 projMatrix;
			Mat4 viewMatrix;
		};
	}
}