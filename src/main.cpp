#include "window.hpp"
#include "utils.hpp"
#include <iostream>

struct Mesh{
	unsigned int vao;
	unsigned int vbo;
	unsigned int shader;
};

Mesh setupTriangle(){
	float positions[12] = {
		-0.5f,  0.5f, 0.5f,
		 0.5f,  0.5f, 0.5f,
		 0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
	};


	Mesh m;

	glGenVertexArrays(1, &m.vao);
	glBindVertexArray(m.vao);

	glGenBuffers(1, &m.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m.vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);

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

	glEnable(GL_DEPTH_TEST);

	Mesh mesh = setupTriangle();
	GLFWwindow* w = windowContext.getWindow();

	float rotation = 0.0f;

	while(!glfwWindowShouldClose(w)){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		rotation += 0.009f;

		glm::mat4 mvp = Core::camera(2.0f, glm::vec2(rotation, rotation));
		
		glUseProgram(mesh.shader);

		int location = glGetUniformLocation(mesh.shader, "u_MVP");
		glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]);

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
