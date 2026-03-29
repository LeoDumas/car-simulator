#include "glad/glad.h"
#include "GLFW/glfw3.h"
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

}

#endif /* UTILS_H_ */