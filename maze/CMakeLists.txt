cmake_minimum_required(VERSION 3.14)
project(Maze)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)

enable_testing ()

add_subdirectory(config)
add_subdirectory(generator)
add_subdirectory(solver)
add_subdirectory(main)

install(TARGETS Maze DESTINATION bin)
