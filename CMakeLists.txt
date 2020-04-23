cmake_minimum_required(VERSION 3.10)

project(Promien VERSION 0.1)


#versioning

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(_buildConfig.h.in _buildConfig.h)

#include
include_directories(./src ./include ./lib/glfw-3.3.2/include ./config)

#target
add_executable(Promien src/main.cpp src/harness.cpp src/plate.cpp src/config.cpp)

#libraries
add_subdirectory(./lib/glfw-3.3.2)
target_link_libraries(Promien glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(Promien OpenGL::GL)

target_include_directories(Promien PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_BINARY_DIR}/*"
)

