add_executable(maze source/main.cpp)

target_link_libraries(maze Boost::boost Boost::program_options)
