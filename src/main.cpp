#include "window.hpp"
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


	glDrawArrays(GL_QUADS, 0, sizeof(positions)/2);
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
