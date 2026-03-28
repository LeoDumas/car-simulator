# Car Simulator

> **Note:** This is a learning project, so things may not be perfect.

The objective of this project is to recreate a car simulator without using any game engine. 

Obviously, the project will use OpenGL (GLFW, GLAD).

For the moment, no real roadmap exists, but the first milestone will be to have a fully working 3D engine that allows users to add 3D objects to it, with shaders and all.

## Dev Stack

* C++ (GLFW, GLAD)
* Make and CMake
* vcpkg

# How to run the project

## Prerequisites

Before building the project, ensure you have the following installed:
* A C++ compiler
* **CMake** and **Make**
* **vcpkg** (for dependency management)

You must also set the `VCPKG_ROOT` environment variable to point to your local vcpkg installation folder.

> Make sure to choose the correct terminal option based on your system for the `vcpkg` tutorial below (Windows -> Powershell/CMD; Linux/MacOS -> bash)

[https://learn.microsoft.com/en-us/vcpkg/get_started/get-started](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started)


```bash
export VCPKG_ROOT="/path/to/your/vcpkg"
```

## How to Build

A `Makefile` is provided to simplify the build process. 

1. **Generate the build files:**
   ```bash
   make create-build
   ```

2. **Compile the project:**
   ```bash
   make build-project
   ```


## How to launch

Once compiled, you can run the simulator with:

```bash
./build/car-sim
```