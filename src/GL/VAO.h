#pragma once

#include <vector>
#include "AttachGL.h"

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
		~VAO();
	};
}

