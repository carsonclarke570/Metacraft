cmake_minimum_required(VERSION 3.13)
project(Daybreak)

# GLFW
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EAMPLES OFF)
option(GLFW_BUILD_TEST OFF)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glfw)

# Compile settings
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

# Includes
include_directories(
        ${PROJECT_SOURCE_DIR}/include/
        ${PROJECT_SOURCE_DIR}/libs/glfw/include/
)

# Sources
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB SHADERS ${PROJECT_SOURCE_DIR}/res/shaders/*.frag
                  ${PROJECT_SOURCE_DIR}/res/shaders/*.geom
                  ${PROJECT_SOURCE_DIR}/res/shaders/*.vert)

source_group("headers" FILES ${HEADERS})
source_group("sources" FILES ${SOURCES})
source_group("shaders" FILES ${SHADERS})

add_definitions(
        -DGLFW_INCLUDE_NONE
        -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${SHADERS} main.cpp)

target_link_libraries(${PROJECT_NAME}
        glfw ${GLFW_LIBRARIES}
)

