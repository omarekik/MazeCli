project(MazeGeneratorTests)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES MazeGeneratorTest.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    GTest::gtest 
    GTest::gtest_main
    Generator
)

gtest_discover_tests(${PROJECT_NAME})
