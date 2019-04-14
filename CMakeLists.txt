cmake_minimum_required(VERSION 2.8)

project(mc-clone-cmake)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME} "src/main.cpp"
                               "src/Camera/Camera.cpp"
                               "src/Chunk/Chunk.cpp"
                               "src/Chunk/ChunkGenerator.cpp"
                               "src/Display/Display.cpp"
                               "src/Mesh/Mesh.cpp"
                               "src/RM/ResourceManager.cpp"
                               "src/Renderer/ChunkRenderer.cpp"
                               "src/Renderer/Renderer.cpp"
                               "src/Shader/Shader.cpp"
                               "src/Texture/Texture.cpp"
                               "src/Utils/Utils.cpp")
target_link_libraries(${PROJECT_NAME} GLEW GL glfw)
