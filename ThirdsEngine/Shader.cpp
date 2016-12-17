#include "Shader.h"

namespace te {
	namespace render {
		
		Shader::Shader(std::string vert, std::string frag) {
			program = loadShaders(("shader/" + vert).c_str(), ("shader/" + frag).c_str());
			idMVP = getUniformID("MVP");
		}

		void Shader::bind() {
			glUseProgram(program);
		}

		GLuint Shader::getUniformID(const std::string& name) const {
			return glGetUniformLocation(program, name.c_str());
		}

		void Shader::setUniform(GLuint id, const Mat4& val) const {
			glUniformMatrix4fv(id, 1, GL_FALSE, &val[0][0]);
		}
	}
}