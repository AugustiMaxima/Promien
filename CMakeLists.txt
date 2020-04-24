cmake_minimum_required(VERSION 3.10)

project(Promien VERSION 0.1)


#versioning

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(_buildConfig.h.in _buildConfig.h)

#include
include_directories(./src ./include ./lib/glfw/include ./config)

#target
add_executable(Promien src/main.cpp src/harness.cpp src/plate.cpp src/config.cpp)

#commands and configs
add_custom_command(OUTPUT config
					COMMAND cp ${CMAKE_SOURCE_DIR}/config/* .)
set_property(SOURCE src/main.cpp APPEND PROPERTY OBJECT_DEPENDS config)

#libraries
add_subdirectory(./lib/glfw)
target_link_libraries(Promien glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(Promien OpenGL::GL)

target_include_directories(Promien PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_BINARY_DIR}/*"
)
