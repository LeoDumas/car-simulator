#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#ifndef WINDOW_H_H
#define WINDOW_H_H

namespace Core{

class Window{

private:
    int _width;
    int _height;
    std::string _title;
    GLFWwindow* _window;
    
public:
    explicit Window(int width, int height, std::string title)
        :_width(width),
        _height(height),
        _title(title)
    {};

    ~Window() = default;

    bool startWindow();

    GLFWwindow* getWindow(){return _window; };

};

}

#endif /* WINDOW_H_H */