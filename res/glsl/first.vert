#version 330
// версия OpenGL

// нулевой атрибут. название атрибута должно совпадать с вызовом функции bindAttribute
in vec3 position;

void main() {
  // записываем координату вершины в глобальную переменную gl_Position,
  // предварительно скастовав значение в тип vec4 (???)
  gl_Position = vec4(position, 1);
}