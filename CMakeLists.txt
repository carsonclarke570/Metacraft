cmake_minimum_required(VERSION 3.13)
project(Daybreak)

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EAMPLES OFF)
option(GLFW_BUILD_TEST OFF)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glfw)

# glad
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glad)

# stb
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/stb)

# Compile settings
set(CMAKE_CXX_STANDARD  11)
if (MSVC)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

# Includes
include_directories(
        ${PROJECT_SOURCE_DIR}/include/
        ${PROJECT_SOURCE_DIR}/libs/glad/include/
        ${PROJECT_SOURCE_DIR}/libs/glfw/include/
)

# Sources
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp
                  ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB SHADERS ${PROJECT_SOURCE_DIR}/res/shaders/*.frag
                  ${PROJECT_SOURCE_DIR}/res/shaders/*.geom
                  ${PROJECT_SOURCE_DIR}/res/shaders/*.vert)
file(COPY ${SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

source_group("headers" FILES ${HEADERS})
source_group("sources" FILES ${SOURCES})
source_group("shaders" FILES ${SHADERS})

add_definitions(
        -DGLFW_INCLUDE_NONE
        -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\"
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        glfw
        ${GLFW_LIBRARIES}
        glad
        stb
)

