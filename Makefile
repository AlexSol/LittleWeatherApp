BUILD_DIR ?= build
BUILD_TYPE ?= Release
JOBS ?= $(shell nproc)

APP_NAME = LittleWeatherApp

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  build-release   Build the project in Release mode"
	@echo "  build-debug     Build the project in Debug mode"
	@echo "  clean           Remove the build directory"


.PHONY: all clean
clean:
	rm -rf $(BUILD_DIR)

configure:
	@echo "Configuring the project with CMake..."
	@echo "Build directory: $(BUILD_DIR)/$(BUILD_TYPE)"
	@echo "Build type: $(BUILD_TYPE)"
	@cmake -S . -B $(BUILD_DIR)/$(BUILD_TYPE) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)


.PHONY: build-release
build-release: BUILD_TYPE = Release
build-release: configure
	cmake --build $(BUILD_DIR)/$(BUILD_TYPE) --config Release -- -j$(JOBS)
	cp $(BUILD_DIR)/$(BUILD_TYPE)/$(APP_NAME) ./$(APP_NAME)

.PHONY: build-debug
build-debug: BUILD_TYPE = Debug
build-debug: configure
	cmake --build $(BUILD_DIR)/$(BUILD_TYPE) --config Debug -- -j$(JOBS)
	cp $(BUILD_DIR)/$(BUILD_TYPE)/$(APP_NAME) ./$(APP_NAME)_debug
