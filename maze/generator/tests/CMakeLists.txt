project(MazeGeneratorTests)


FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/8aa657ee397a3273f9d2bb14a10b39fd1d556a77.zip
)
FetchContent_MakeAvailable(googletest)

set(SOURCES MazeGeneratorTest.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest 
    gtest_main
    Generator
)

gtest_discover_tests(${PROJECT_NAME})
