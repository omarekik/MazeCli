#pragma once

#include <vector>
#include <string>
#include <stack>

class MazeSolver {
public:
    MazeSolver(std::wstring maze);
    bool deepFirstSearch();
    int & getWidth(){return m_Width;}
    int & getHeight(){return m_Height;}
    std::string serializeStartingPoint(){ return "(" + std::to_string(m_StartingPoint.first) + ", " + 
                                                    std::to_string(m_StartingPoint.second) + ")"; };
    std::string serializeEndingPoint(){ return "(" + std::to_string(m_EndingPoint.first) + ", " + 
                                                    std::to_string(m_EndingPoint.second) + ")"; };
    std::string serializeGrid();
    std::wstring serializeSolution();

private:
    bool dfs_help(int i, int j);

    int m_Width;
    int m_Height;
    std::vector<std::vector<int>> m_Grid; // maze 2D array
	std::pair<int, int> m_StartingPoint; // index i and j in m_Grid
    std::pair<int, int> m_EndingPoint; 
	int m_DfsPathCounter;
	int m_DfsStepCounter;
    std::vector<std::vector<bool>> m_VisitedPositions;
};