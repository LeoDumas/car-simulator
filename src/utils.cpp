#include "utils.hpp"

namespace Core{

// Shader utils
unsigned int CompileShader(unsigned int type, const std::string& source){
    
    unsigned int id = glCreateShader(type);
    const char* str = source.c_str();
    glShaderSource(id, 1, &str, nullptr);
    glCompileShader(id);
    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if(result == GL_FALSE){
        int len; 
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char message[len];
        glGetShaderInfoLog(id, len, &len, message);

        std::cout << "Error on: "<< (type == GL_VERTEX_SHADER ? " vertex " : " fragment ") << "shader" << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    
    unsigned int prog = glCreateProgram();

    unsigned int vertS = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragS = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(prog, vertS);
    glAttachShader(prog, fragS);

    glLinkProgram(prog);
    glValidateProgram(prog);

    glDeleteShader(vertS);
    glDeleteShader(fragS);

    return prog;
}


}