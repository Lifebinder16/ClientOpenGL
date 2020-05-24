#pragma once

// Этот модуль создан для обеспечения правильного порядка загрузки хедеров
#include "GL/glew.h"
#include <GL/gl.h> // ! gl.h должен быть загружен ПОСЛЕ загрузки glew.h
#include <GLFW/glfw3.h>