#include <gtest/gtest.h>
#include "MazeGenerator.h"

TEST(MazeGenerator, grid)
{
    std::string res = "S ███████\n"
                      "  █ █ █ █\n"
                      "█████████\n"
                      "█ █ █ █ █\n"
                      "█████████\n"
                      "█ █ █ █  \n"
                      "███████ E\n";
    MazeGenerator maze = MazeGenerator(3, 4, 3);
    EXPECT_STREQ(maze.serialize().c_str(), res.c_str());
}

TEST(MazeGenerator, kruskal)
{
    std::string res = "S ███████\n"
                      "        █\n"
                      "███ █████\n"
                      "█       █\n"
                      "█ ███ ███\n"
                      "█ █      \n"
                      "███████ E\n";
    MazeGenerator maze = MazeGenerator(3, 4, 3);
    maze.kruskal();
    EXPECT_STREQ(maze.serialize().c_str(), res.c_str());
}
