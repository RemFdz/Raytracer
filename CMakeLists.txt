cmake_minimum_required(VERSION 3.26)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(EXECUTABLE_OUTPUT_PATH ../.)
add_executable(raytracer ${SOURCES}
        src/math/point3d/Point3D.hpp
        src/objects/IObject3D.hpp
        src/ray/Ray3D.hpp
        src/objects/shapes/sphere/Sphere.hpp
        src/objects/shapes/sphere/Sphere.cpp
        src/display/DIsplay.hpp)
target_include_directories(raytracer PUBLIC includes)
