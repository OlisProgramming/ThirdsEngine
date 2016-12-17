#include "Camera.h"

namespace te {
	namespace render {
		Camera::Camera(Vec3 pos, Vec3 target, Vec3 up) :
			pos(pos), target(target), up(up) {
			updateMatrices();
		}

		void Camera::updateMatrices() {
			projMatrix = Mat4Project(80.0, 4.0 / 3.0, 0.1, 100.0);
			viewMatrix = Mat4View(pos, target, up);
		}
	}
}