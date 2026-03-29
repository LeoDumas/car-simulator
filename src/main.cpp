#include "window.hpp"
#include "utils.hpp"
#include <iostream>

struct Mesh{
	unsigned int vao;
	unsigned int vbo;
	unsigned int shader;
};

Mesh setupTriangle(){
	float positions[8] = {
		-0.5f,  0.5f,
		 0.5f,  0.5f,
		 0.5f, -0.5f,
		-0.5f, -0.5f,
	};


	Mesh m;

	glGenVertexArrays(1, &m.vao);
	glBindVertexArray(m.vao);

	glGenBuffers(1, &m.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m.vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);

	std::string vertexShader = Core::loadShaderFile("src/shaders/vertex.vs");
	std::string fragmentShader = Core::loadShaderFile("src/shaders/fragment.fs");

	m.shader = Core::CreateShader(vertexShader, fragmentShader);

	return m;

}

int main(){

	Core::Window windowContext(1280, 720, "Car simulator");

	if(!windowContext.startWindow()){
		std::cout << "Failed to start the window" << std::endl;
		return 0;
	}

	Mesh mesh = setupTriangle();
	GLFWwindow* w = windowContext.getWindow();

	while(!glfwWindowShouldClose(w)){
		
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(mesh.shader);
		glBindVertexArray(mesh.vao);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glfwSwapBuffers(w);
		glfwPollEvents();
	}

	glDeleteProgram(mesh.shader);
	glDeleteBuffers(1, &mesh.vbo);
	glDeleteVertexArrays(1, &mesh.vao);
	glfwDestroyWindow(w);
	glfwTerminate();
	return 0;
}
