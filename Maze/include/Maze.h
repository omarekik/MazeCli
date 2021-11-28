#include <vector>
#include <string>

enum Direction { UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8};
class Maze {
public:
    Maze(int height, int width, int seed);
    std::string serialize();
    void kruskal();
private:
    Direction oppositeDirection(Direction direction);
    int cellIndex(int x, int y);

    int m_Width;
    int m_Height;
    std::vector<std::vector<int>> grid;
};