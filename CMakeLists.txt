cmake_minimum_required(VERSION 3.14)

project(
	car-sim
)


add_executable(
	car-sim
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_sources(
	car-sim
	PRIVATE
		src/main.cpp
		src/window.cpp
		src/utils.cpp
)

target_include_directories(
	car-sim
	PRIVATE
		inc
)

target_link_libraries(
	car-sim
	PRIVATE
		glad::glad
		glfw
		OpenGL::GL	
)