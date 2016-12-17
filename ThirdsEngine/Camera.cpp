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
		}

		void Camera::rotatePitch(float angle) {
			Vec3 axis = Nor(Cross(AxisY, front));
			front = Rotate(front, angle, axis);
			up = Cross(front, axis);
		}

		void Camera::rotateYaw(float angle) {
			Vec3 axis = Nor(Cross(AxisY, front));
			front = Rotate(front, angle, AxisY);
			up = Cross(front, axis);
		}

		void Camera::updateMatrices() {
			projMatrix = Mat4Project(80.0, 4.0 / 3.0, 0.1, 100.0);
			viewMatrix = Mat4View(pos, pos+front, up);
		}
	}
}