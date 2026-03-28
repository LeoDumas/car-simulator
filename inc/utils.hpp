#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include <iostream>

#ifndef UTILS_H_
#define UTILS_H_

namespace Core{

unsigned int CompileShader(unsigned int type, const std::string& source);

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

}

#endif /* UTILS_H_ */