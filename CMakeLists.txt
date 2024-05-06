cmake_minimum_required(VERSION 3.26)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
find_package(PkgConfig REQUIRED)
pkg_search_module(SFML REQUIRED sfml-graphics sfml-window sfml-system sfml-audio)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(EXECUTABLE_OUTPUT_PATH ../.)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -Werror")
add_executable(raytracer ${SOURCES}
        src/objects/IObject3D.hpp
        src/graphics/ray/Ray3D.hpp
        src/objects/shapes/sphere/Sphere.hpp
        src/objects/shapes/sphere/Sphere.cpp
        src/display/SfmlDisplay.hpp
        src/core/Core.cpp
        src/graphics/color/Color.hpp
        src/graphics/scene/Scene.hpp
        src/graphics/camera/Camera.cpp
        src/graphics/ray/Ray3D.cpp
        src/models/HitData.hpp
        src/graphics/scene/Scene.cpp
        src/models/RenderMode.hpp
        src/objects/objectlist/ObjectList.hpp
        src/utils/Range.hpp
        src/utils/Randomizer.hpp
        src/graphics/materials/IMaterial.hpp
        src/graphics/materials/lambertian/Lambertian.cpp
        src/graphics/materials/mirror/Mirror.hpp)
target_link_libraries(raytracer sfml-graphics sfml-window sfml-system sfml-audio config++)
target_include_directories(raytracer PUBLIC includes)
