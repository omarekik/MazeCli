#include "MazeGenerator.h"
#include <tuple>
#include <stdlib.h>
#include <algorithm>

//
// Disjoint set is explained in :
//  https://betterprogramming.pub/using-disjoint-set-union-find-to-build-a-maze-generator-7462ea3b8632
//
class DisjointSet {

public:
    DisjointSet(int size) 
    {
        rank.resize(size);
        parent.reserve(size);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    bool sameSet(int first_set, int second_set) 
    {
        return find(first_set) == find(second_set);
    }

    void unifySet(int first_set, int second_set) 
    {
        int parent_first_set = find(first_set), parent_second_set = find(second_set);
        if (rank[parent_first_set] > rank[parent_second_set]) 
        {
            parent[parent_second_set] = parent_first_set;
        }
        else 
        {
            parent[parent_first_set] = parent_second_set;
            if (rank[parent_first_set] == rank[parent_second_set])
            {
                rank[parent_second_set]++;
            }
        }
    }
private:
    int find(int element) 
    {
        if(element != parent[element])
        {
            parent[element] = find(parent[element]);
        }
        return parent[element];
    }
    std::vector<int> parent;
    std::vector<int> rank;
};

struct Wall {
    Wall(int abscissa, int ordinate, Direction direction) : m_Abscissa(abscissa)
                                                          , m_Ordinate(ordinate)
                                                          , m_Direction(direction) 
                                                          {};
    int m_Abscissa;
    int m_Ordinate;
    Direction m_Direction;
};

MazeGenerator::MazeGenerator(int height, int width, int seed) : m_Width(width)
                                            , m_Height(height)
{
    srand(seed);
    m_Grid.assign(m_Height, std::vector<int>(m_Width));
}


std::string MazeGenerator::serialize() 
{
    std::string res = "";
    //
    // First line closing maze from the top but the start point
    //
    res += "S ";
    for (int j = 0; j < m_Width - 1; j++)
        res +=  "██";
    res +=  "█\n";

    for (int i = 0; i < m_Height; i ++) 
    {
        //
        // Column closing maze from the left but the start point
        //
        if(i == 0)
        {
            res += " ";
        }
        else
        {
            res +=  "█"; 
        }
        
        for (int j = 0; j < m_Width; j ++) 
        {
            if(m_Grid[i][j] & RIGHT || (i == m_Height - 1 && j == m_Width - 1))
            {
                res +=  "  ";
            }
            else
            {
                res += " █";
            }
        }
        res +=  "\n█";
        for (int j = 0; j < m_Width; j ++) 
        {
            if(i == m_Height - 1 && j == m_Width - 1)
            {
                res +=  " E";
            }
            else
            {
                if(m_Grid[i][j] & DOWN)
                {
                    res += " █";
                }
                else
                {
                    res += "██";
                }
            }
        }
        res +=  "\n";
    }
    return res;
}

int MazeGenerator::cellIndex(int x, int y) 
{
    return x * m_Width + y;
}

Direction MazeGenerator::oppositeDirection(Direction direction)
{
    switch (direction)
    {
    case UP:
        return DOWN;
    case DOWN:
        return UP;
    case RIGHT:
        return LEFT;
    case LEFT:
        return RIGHT;
    }
    return DOWN;
}
//
// Kruskal maze is explained in:
// https://weblog.jamisbuck.org/2011/1/3/maze-generation-kruskal-s-algorithm
//
void MazeGenerator::kruskal() {
    std::vector<Wall> walls;
    walls.reserve(m_Width * m_Height);
    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++) {
            if (j) walls.emplace_back(Wall(i, j, LEFT));
            if (i) walls.emplace_back(Wall(i, j, UP));
        }
    }
    std::random_shuffle(walls.begin(), walls.end());

    DisjointSet disjoint_set(m_Height * m_Width);
    for (auto & wall : walls) {
        const int & wall_abscissa = wall.m_Abscissa;
        const int & wall_ordinate = wall.m_Ordinate;
        const Direction & wall_direction = wall.m_Direction;
        auto [next_abscissa, next_ordinate] = [&]
        {
            switch (wall_direction)
            {
            case UP:
                return std::make_tuple(wall_abscissa - 1, wall_ordinate);
            case DOWN:
                return std::make_tuple(wall_abscissa + 1, wall_ordinate);
            case RIGHT:
                return std::make_tuple(wall_abscissa, wall_ordinate + 1);
            case LEFT:
                return std::make_tuple(wall_abscissa, wall_ordinate - 1);
            }
            return std::make_tuple(wall_abscissa - 1, wall_ordinate);
        }();
        int current = cellIndex(wall_abscissa, wall_ordinate);
        int next = cellIndex(next_abscissa, next_ordinate);
        if (!disjoint_set.sameSet(current, next)) 
        {
            disjoint_set.unifySet(current, next);
            m_Grid[wall_abscissa][wall_ordinate] |= wall_direction;
            m_Grid[next_abscissa][next_ordinate] |= oppositeDirection(wall_direction);
        }
    }
}
