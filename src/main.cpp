#include "window.hpp"
#include "utils.hpp"
#include <iostream>

void render(){
	
	float positions[8] = {
		-0.5f,  0.5f,
		 0.5f,  0.5f,
		 0.5f, -0.5f,
		-0.5f, -0.5f,
	};
	
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, (6*sizeof(float)), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);

	std::string vertexShader = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main(){\n"
		"	gl_Position = position;\n"
		"}";

	std::string fragmentShader = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;"
		"\n"
		"void main(){\n"
		"	color = vec4(1.0, 0.0, 1.0, 1.0);\n"
		"}";
	unsigned int shader = Core::CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
}

int main(){

	Core::Window windowContext(1280, 720, "Car simulator");

	if(!windowContext.startWindow()){
		std::cout << "Failed to start the window" << std::endl;
		return 0;
	}

	GLFWwindow* w = windowContext.getWindow();

	while(!glfwWindowShouldClose(w)){
		
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(w);
		glfwPollEvents();
	}

	glfwDestroyWindow(w);
	glfwTerminate();
	return 0;
}
