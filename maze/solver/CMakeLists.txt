project(Solver)

add_subdirectory(tests)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/MazeSolver.h
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/MazeSolver.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
