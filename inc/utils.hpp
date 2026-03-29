#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef UTILS_H_
#define UTILS_H_

namespace Core{

unsigned int CompileShader(unsigned int type, const std::string& source);

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

std::string loadShaderFile(const std::string& filePath);

glm::mat4 camera(float Translate, glm::vec2 const& Rotate);

}

#endif /* UTILS_H_ */