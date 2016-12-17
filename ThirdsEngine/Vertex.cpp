#include "Vertex.h"

namespace te {
	namespace render {

		Vertex::Vertex(Vec3 pos) :
			pos(pos) {}

		Vec3* Vertex::getPos() { return &pos; }
	}
}