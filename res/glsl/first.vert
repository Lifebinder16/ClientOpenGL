#version 330
// ������ OpenGL

// ������� �������. �������� �������� ������ ��������� � ������� ������� bindAttribute
in vec3 position;

void main() {
  // ���������� ���������� ������� � ���������� ���������� gl_Position,
  // �������������� ��������� �������� � ��� vec4 (???)
  gl_Position = vec4(position, 1);
}