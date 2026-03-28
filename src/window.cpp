#include "window.hpp"
#include <iostream>

namespace Core{

bool Window::startWindow()
{
	
	if(!glfwInit()){
		return false;
	}

	_window = glfwCreateWindow(_width, _height, _title.c_str(), glfwGetPrimaryMonitor(), NULL);

	if(!_window){
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(_window);

	int version = gladLoadGL();
	if(version == 0){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	std::cout << "Loaded OpenGL: " << version << std::endl;

    return true;

}

}