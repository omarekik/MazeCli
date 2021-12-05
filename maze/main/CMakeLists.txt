project(Maze)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Configs
    Generator
    Solver
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${Config_SOURCE_DIR}/include
)
