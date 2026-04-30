cmake_minimum_required(VERSION 3.16)

project(LittleWeatherApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CheckCXXCompilerFlag)


# ------ Sanitizers ----
add_library(sanitizers INTERFACE)
target_compile_options(sanitizers INTERFACE
  $<$<AND:$<PLATFORM_ID:Linux>,$<CONFIG:Debug>,$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>>:
    -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize=vptr>
)

target_link_options(sanitizers INTERFACE
  $<$<AND:$<PLATFORM_ID:Linux>,$<CONFIG:Debug>,$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>>:
    -fsanitize=address,undefined>
)

add_executable(${PROJECT_NAME}
    src/atlas.h
    src/providers/providerOpenMeteo.cpp
    src/providers/providers.cpp
    src/main.cpp
    src/parser.cpp
    src/settings.cpp
    src/ui.cpp
    src/wallpaper.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<AND:$<PLATFORM_ID:Linux>,$<CONFIG:Debug>,$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>>:
    -g -O0>
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sanitizers
        -lraylib
        -lGL
        -lm
        -lpthread
        -ldl
        -lrt
        -lX11
)