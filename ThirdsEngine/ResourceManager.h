#pragma once

#include <sstream>
#include <vector>
#include <string>

#include "Math.h"
#include "Mesh.h"

namespace te {

	/** Read file into string. */
	inline std::string readFile(const std::string& path) {
		std::ostringstream buf; std::ifstream input(path.c_str()); buf << input.rdbuf(); return buf.str();
	}

	inline std::vector<GLfloat>* vec3ToGLfloat(std::vector<Vec3>* vec3s) {
		std::vector<GLfloat>* floats = new std::vector<GLfloat>();
		for (Vec3 v : *vec3s) {
			floats->push_back(v.x);
			floats->push_back(v.y);
			floats->push_back(v.z);
		}
		return floats;
	}

	inline render::Mesh* loadOBJ(std::string name) {
		std::vector<unsigned short> vertexIndices, uvIndices, normalIndices;
		std::vector<Vec3> temp_vertices;
		std::vector<Vec2> temp_uvs;
		std::vector<Vec3> temp_normals;

		std::ifstream file;
		file.open("mesh/" + name + ".obj");
		std::string line;
		while (std::getline(file, line)) {
			if (line.substr(0, 2) == "v ") {
				Vec3 vertex;
				std::istringstream iss(line.substr(2, line.length() - 2));
				if (!(iss >> vertex.x >> vertex.y >> vertex.z)) { break; }
				temp_vertices.push_back(vertex);
			}
			else if (line.substr(0, 2) == "vt") {
				Vec2 coord;
				std::istringstream iss(line.substr(3, line.length() - 3));
				if (!(iss >> coord.x >> coord.y)) { break; }
				temp_uvs.push_back(coord);
			}
			else if (line.substr(0, 2) == "vn") {
				Vec3 normal;
				std::istringstream iss(line.substr(3, line.length() - 3));
				if (!(iss >> normal.x >> normal.y >> normal.z)) { break; }
				temp_uvs.push_back(normal);
			}
			else if (line.substr(0, 2) == "f ") {
				printf("face\n");
				unsigned short vIndex[3], vnIndex[3], vtIndex[3];
				std::string a, b, c;
				std::istringstream iss(line.substr(2, line.length() - 2));
				if (!(iss >> a >> b >> c)) { break; }

				printf("%s, %s, %s\n", a.c_str(), b.c_str(), c.c_str());

				char c1, c2, c3, c4, c5, c6;
				printf("2");
				std::istringstream issA(a);
				if (!(issA >> vIndex[0] >> c1 >> vtIndex[0] >> c2 >> vnIndex[0])) { break; }
				printf("3");
				std::istringstream issB(b);
				if (!(issB >> vIndex[1] >> c3 >> vtIndex[1] >> c4 >> vnIndex[1])) { printf("err2"); break; }
				printf("4");
				std::istringstream issC(c);
				if (!(issC >> vIndex[2] >> c5 >> vtIndex[2] >> c6 >> vnIndex[2])) { break; }

				printf("...");

				vertexIndices.push_back(vIndex[0]);
				vertexIndices.push_back(vIndex[1]);
				vertexIndices.push_back(vIndex[2]);
				uvIndices.push_back(vtIndex[0]);
				uvIndices.push_back(vtIndex[1]);
				uvIndices.push_back(vtIndex[2]);
				normalIndices.push_back(vnIndex[0]);
				normalIndices.push_back(vnIndex[1]);
				normalIndices.push_back(vnIndex[2]);

				printf("done face\n");
			}
		}

		render::Mesh* mesh = new render::Mesh();
		mesh->setVertices(vec3ToGLfloat(&temp_vertices), &vertexIndices);
		return mesh;
	}
}