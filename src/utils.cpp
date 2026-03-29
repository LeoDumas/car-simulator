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

std::string loadShaderFile(const std::string& filePath){

    std::ifstream fileStream(filePath);
    if(!fileStream.is_open()){
        std::cout << "Failed to open shader located at: " << filePath << std::endl;
        return "";
    }

    std::stringstream sBuffer;
    sBuffer << fileStream.rdbuf();
    return sBuffer.str();
}

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}


}