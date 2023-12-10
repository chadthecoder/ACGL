cmake_minimum_required(VERSION 3.16)
project(ACGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 CONFIG REQUIRED)

set(glad_DIR vcpkg_installed/x64-linux/share/glad)
find_package(glad CONFIG REQUIRED)

set(glm_DIR vcpkg_installed/x64-linux/share/glm)
find_package(glm CONFIG REQUIRED)

find_package(fmt CONFIG REQUIRED)

set(CPP_DIR src/ACGL)
#set(HPP_DIR include)
set(CPP ${CPP_DIR}/stb.cpp ${CPP_DIR}/VBO.cpp
    ${CPP_DIR}/VAO.cpp ${CPP_DIR}/Shader.cpp ${CPP_DIR}/Texture.cpp
    ${CPP_DIR}/EBO.cpp ${CPP_DIR}/Camera.cpp)
#set(HPP ${HPP_DIR}/VBO.h ${HPP_DIR}/shaderClass.h lib/stb_image.h)
#set(HPP_AND_CPP ${CPP} ${HPP})

#add_subdirectory(src)
include_directories(include)
include_directories(vcpkg_installed/x64-linux/include)
add_library(${PROJECT_NAME} SHARED ${CPP})
#target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
#add_executable(${PROJECT_NAME} ${CPP})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE vcpkg_installed/x64-linux/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad::glad glm::glm fmt::fmt)

#include_directories(include)
#add_library(openGL_vcpkg .cpp)
#include in target_link_libraries


#add_subdirectory(openGL_vcpkg)
#add_library(glm::glm ALIAS glm)