#pragma once

#include "Math.h"

namespace te {
	namespace render {

		class Vertex {
		public:
			Vertex(Vec3 pos);
			Vec3* getPos();

		private:
			Vec3 pos;
		};
	}
}

