#pragma once

#include <vector>
#include <string>

enum Direction { UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8};
class MazeGenerator {
public:
    MazeGenerator(int height, int width, int seed);
    std::string serialize();
    void kruskal();

private:
    inline Direction oppositeDirection(Direction direction);
    inline int cellIndex(int x, int y);

    int m_Width;
    int m_Height;
    std::vector<std::vector<int>> m_Grid;
	std::pair<int, int> startingPoint;
    std::pair<int, int> endingPoint;
};