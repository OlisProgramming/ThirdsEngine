#pragma once

#include "Math.h"

namespace te {
	namespace render {
		class Camera {
		public:
			Camera(Vec3 pos, Vec3 front, Vec3 up);
			void updateMatrices();

			void move(Vec3 dir, float distance);

			inline Vec3 getPos() const { return pos; }
			inline void setPos(const Vec3& pos) { this->pos = pos; }

			inline Vec3 getFront() const { return front; }
			inline void setFront(const Vec3& front) { this->front = front; }

			inline Vec3 getUp() const { return up; }
			inline void setUp(const Vec3& up) { this->up = up; }

			inline Vec3 getLeft() const { return Cross(up, getFront()); }
			inline Vec3 getRight() const { return Cross(getFront(), up); }

			inline Mat4 getView() const { return viewMatrix; }
			inline Mat4 getProject() const { return projMatrix; }

		private:
			Vec3 pos;
			Vec3 front;
			Vec3 up;
			Mat4 projMatrix;
			Mat4 viewMatrix;
		};
	}
}