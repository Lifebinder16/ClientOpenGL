#pragma once

#include <string>
#include "../GL/AttachGL.h"

// В терминологии OpenGL группа различных связанных шейдеров называется "Program",
// поэтому и класс будет называться также.

namespace GL 
{
	class ShadersProgram
	{
	private:
		GLuint mProgram;
		GLuint mVertexShader;
		GLuint mFragmentShader;
		GLuint loadShader(const std::string& path, GLenum shaderType);
	public:
		ShadersProgram(const std::string& name);
		void link();
		void bindAttribute(GLuint index, const std::string& name);
		void use();
		~ShadersProgram();
	};
}

