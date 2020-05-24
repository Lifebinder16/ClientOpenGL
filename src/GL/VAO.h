#pragma once

#include <vector>
#include "AttachGL.h"
#include "../glm/glm.hpp"

namespace GL
{
	// Vertex array object
	class VAO
	{
	private:
		GLuint mVao;
		std::vector<GLuint> mBuffers;
	public:
		VAO();
		VAO(const VAO&) = delete;
		void bind();
		void draw(GLsizei count);
		void addVertexBufferObject(const std::vector<float>& data);
		void addVertexBufferObject(const std::vector<glm::vec2>& data);
		void addVertexBufferObject(const std::vector<glm::vec3>& data);
		void addVertexBufferObject(const std::vector<glm::vec4>& data);
		~VAO();
	};
}

