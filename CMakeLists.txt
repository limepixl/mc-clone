cmake_minimum_required(VERSION 3.14)

project(mc-clone-cmake)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} GLEW GL glfw)
