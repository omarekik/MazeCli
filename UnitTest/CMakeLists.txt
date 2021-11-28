include(GoogleTest)

FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/8aa657ee397a3273f9d2bb14a10b39fd1d556a77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(Source ${CMAKE_SOURCE_DIR}/Maze/source)

add_executable(unitTest main.cpp 
                        MazeTest.cpp
                        ${Source}/Maze.cpp)

target_link_libraries(unitTest gtest_main Boost::boost)

gtest_discover_tests(unitTest)
