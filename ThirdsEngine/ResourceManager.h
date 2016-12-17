#pragma once

#include <sstream>
#include <vector>
#include <string>

#include <GL/glew.h>

#include "SOIL.h"

#include "Math.h"
#include "Mesh.h"

#define MESH_DIR		"mesh/"
#define	MESH_OBJ_EXT	".obj"
#define IMG_DIR			"img/"
#define IMG_BMP_EXT		".bmp"

namespace te {

	/** Read file into string. */
	inline std::string readFile(const std::string& path) {
		std::ostringstream buf; std::ifstream input(path.c_str()); buf << input.rdbuf(); return buf.str();
	}

	inline GLuint loadBMP(std::string name) {
		GLuint tex_2d = SOIL_load_OGL_texture
		(
			(IMG_DIR + name + IMG_BMP_EXT).c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, tex_2d);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return tex_2d;
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
		file.open(MESH_DIR + name + MESH_OBJ_EXT);
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
				unsigned short vIndex[3], vnIndex[3], vtIndex[3];
				std::string a, b, c;
				std::istringstream iss(line.substr(2, line.length() - 2));
				if (!(iss >> a >> b >> c)) { break; }

				char c1, c2, c3, c4, c5, c6;
				std::istringstream issA(a);
				if (!(issA >> vIndex[0] >> c1 >> vtIndex[0] >> c2 >> vnIndex[0])) { break; }
				std::istringstream issB(b);
				if (!(issB >> vIndex[1] >> c3 >> vtIndex[1] >> c4 >> vnIndex[1])) { break; }
				std::istringstream issC(c);
				if (!(issC >> vIndex[2] >> c5 >> vtIndex[2] >> c6 >> vnIndex[2])) { break; }

				vertexIndices.push_back(vIndex[0] - 1);
				vertexIndices.push_back(vIndex[1] - 1);
				vertexIndices.push_back(vIndex[2] - 1);
				uvIndices.push_back(vtIndex[0] - 1);
				uvIndices.push_back(vtIndex[1] - 1);
				uvIndices.push_back(vtIndex[2] - 1);
				normalIndices.push_back(vnIndex[0] - 1);
				normalIndices.push_back(vnIndex[1] - 1);
				normalIndices.push_back(vnIndex[2] - 1);
			}
		}

		render::Mesh* mesh = new render::Mesh();
		mesh->setVertices(vec3ToGLfloat(&temp_vertices), &vertexIndices);
		return mesh;
	}
}