cmake_minimum_required(VERSION 3.16)

project(LittleWeatherApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CheckCXXCompilerFlag)

add_executable(${PROJECT_NAME}
    src/atlas.h
    src/client.cpp
    src/main.cpp
    src/parser.cpp
    src/settings.cpp
    src/ui.cpp
    src/wallpaper.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        -lraylib
        -lGL
        -lm
        -lpthread
        -ldl
        -lrt
        -lX11
)