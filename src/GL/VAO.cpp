#include "VAO.h"
#include <iostream>

GL::VAO::VAO()
{
	// ���������� ������ ������
	glGenVertexArrays(1, &mVao);
	// ����������� ����� ��������� ��� � GL,
	// ����� �� ����������� NVidia ������� AV ��� ������� ���������� ������� ������
	bind();
};

void GL::VAO::bind()
{
	glBindVertexArray(mVao);
}

void GL::VAO::draw(GLsizei count)
{

	// ��������� ������� ������ ������ � GL
	bind();
	
	// ��������� � ������ ���������� ������ ��������� ������
	for (size_t i = 0; i < mBuffers.size(); i++) {
		glEnableVertexAttribArray(i);
	}

	// ������
	glDrawArrays(GL_TRIANGLES, 0, count);

	// ��������� ������� �� ������
	for (size_t i = 0; i < mBuffers.size(); i++) {
		glDisableVertexAttribArray(i);
	}

}

void GL::VAO::addVertexBufferObject(const std::vector<float>& data)
{
	// ������ � ������� ������ ����� ������ (�����������)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

GL::VAO::~VAO()
{
	glDeleteBuffers(mBuffers.size(), mBuffers.data());
	glDeleteVertexArrays(1, &mVao);
};