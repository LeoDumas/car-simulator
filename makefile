create-build:
	@if [ -z "$(VCPKG_ROOT)" ]; then \
		echo "Error : VCPKG_ROOT is not defined"; \
		exit 1; \
	fi
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake

build-project:
	cmake --build build

run:
	cmake --build build && ./build/car-sim
