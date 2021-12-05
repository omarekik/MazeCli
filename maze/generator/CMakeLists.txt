project(Generator)

add_subdirectory(tests)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/MazeGenerator.h
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/MazeGenerator.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
