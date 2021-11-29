

add_executable(maze source/main.cpp
                    source/MazeGenerator.cpp
                    source/MazeSolver.cpp)

target_link_libraries(maze Boost::boost Boost::program_options)
