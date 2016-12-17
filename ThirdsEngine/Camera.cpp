#include "Camera.h"

#include <stdio.h>

namespace te {
	namespace render {
		Camera::Camera(Vec3 pos, Vec3 front, Vec3 up) :
			pos(pos), front(front), up(up) {
			updateMatrices();
		}

		void Camera::move(Vec3 dir, float distance) {
			pos += dir*distance;
			Vec3Print(dir);
			Vec3Print(pos);
			printf("\n");
		}

		void Camera::updateMatrices() {
			projMatrix = Mat4Project(80.0, 4.0 / 3.0, 0.1, 100.0);
			viewMatrix = Mat4View(pos, pos+front, up);
		}
	}
}