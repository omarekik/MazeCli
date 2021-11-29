#include <gtest/gtest.h>
#include "MazeSolver.h"

TEST(MazeSolver, grid)
{
    MazeSolver maze = MazeSolver(L"S ███████\n"
                                  "        █\n"
                                  "███ █████\n"
                                  "█       █\n"
                                  "█ ███ ███\n"
                                  "█ █      \n"
                                  "███████ E\n");
    ASSERT_EQ(maze.getWidth(), 10);
    ASSERT_EQ(maze.getHeight(), 7);
    ASSERT_STREQ(maze.serializeStartingPoint().c_str(), "(0, 0)");
    ASSERT_STREQ(maze.serializeEndingPoint().c_str(), "(6, 8)");

    maze.deepFirstSearch();

    //
    // 0: space
    // 1: wall
    // 4: solved path
    //
    ASSERT_STREQ(maze.serializeGrid().c_str(), "841111111"
                                               "044400001"
                                               "111411111"
                                               "100444001"
                                               "101114111"
                                               "101004444"
                                               "111111109");
}