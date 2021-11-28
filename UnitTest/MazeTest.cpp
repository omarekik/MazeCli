#include <gtest/gtest.h>
#include "Maze.h"

TEST(MazeTest, grid)
{
    Maze maze = Maze(3, 4, 3);
    EXPECT_STREQ(maze.serialize().c_str(), "█████████\n"
                                           "█ █ █ █ █\n"
                                           "█████████\n"
                                           "█ █ █ █ █\n"
                                           "█████████\n"
                                           "█ █ █ █ █\n"
                                           "█████████\n");
}

TEST(MazeTest, kruskal)
{
    Maze maze = Maze(3, 4, 3);
    maze.kruskal();
    EXPECT_STREQ(maze.serialize().c_str(), "█████████\n"
                                           "█       █\n"
                                           "███ █████\n"
                                           "█       █\n"
                                           "█ ███ ███\n"
                                           "█ █     █\n"
                                           "█████████\n");
}
