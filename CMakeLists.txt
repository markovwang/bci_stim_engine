cmake_minimum_required(VERSION 3.12)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 ")
project(STIM_ENGINE LANGUAGES C CXX)

# 请务必在其他文件夹编译

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new build directory and run CMake from there.\n")
endif()
if(WIN32)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_WARNINGS _WINSOCK_DEPRECATED_NO_WARNINGS)
endif()
include_directories("src/")

# configure compiler command
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O0 -g")
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O3")
endif()


option(USE_LAST_SFML "use the latest version of SFML" ON)

if(USE_LAST_SFML)
# 添加SFML目录
add_subdirectory("deps/SFML")
else()
add_subdirectory("deps/SFML-2.5.1")
endif(USE_LAST_SFML)

# 添加kafka目录
add_subdirectory("deps/kafka/include")

set(USE_LIBCPP OFF)
add_subdirectory("deps/entt-3.10.3")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory("deps/fmt-9.0.0")

# file(GLOB_RECURSE COMPONENT_SRC src/components/*.cc)
# add_library(components ${COMPONENT_SRC})
# target_link_libraries(components PUBLIC sfml-system sfml-graphics sfml-window)
# target_include_directories(components PUBLIC src/components)

# add engine dir
file(GLOB_RECURSE ENGINE_SRC src/engine/*.cc)
add_library(engine STATIC ${ENGINE_SRC})
target_include_directories(engine PUBLIC src/engine/)
target_link_libraries(engine PUBLIC EnTT::EnTT sfml-system sfml-graphics sfml-window)

# add graphics dir
file(GLOB_RECURSE GRAPHICS_SRC src/graphics/*.cc )
add_library(graphics STATIC ${GRAPHICS_SRC})
target_include_directories(graphics PUBLIC src/graphics/)
target_link_libraries(graphics PUBLIC EnTT::EnTT sfml-system sfml-graphics sfml-window)

# main executable file
add_executable(${PROJECT_NAME} src/main.cc)
target_link_libraries(${PROJECT_NAME} PUBLIC engine graphics modern-cpp-kafka-api fmt)