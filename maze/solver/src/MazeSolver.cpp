#include "MazeSolver.h"
#include <memory>
#include <iostream>
#include <utility>
#include <map>

MazeSolver::MazeSolver(std::wstring maze) 
{
    m_Width = maze.find('\n');
    if(m_Width > 0)
    {
        ++m_Width;  // to include \n character
        m_Height = maze.size() / m_Width;
    }
    
    m_Grid.assign(m_Height, std::vector<int>(m_Width - 1));//zero all the grid

    for (int i = 0; i < m_Height; ++i)
    {
        for (int j = 0; j < m_Width - 1; ++j)
        {
            const wchar_t maze_element = maze[m_Width * i + j];
            if(maze_element == L'█')
            {
                m_Grid[i][j] = 1;
            }
            else if(maze_element == 'S')
            {
                m_StartingPoint = std::make_pair(i, j);
            }
            else if(maze_element == 'E')
            {
                m_EndingPoint = std::make_pair(i, j);
            }
        }
    }
}

std::string MazeSolver::serializeGrid()
{
    std::string res = "";
    for (int i = 0; i < m_Height; ++i)
    {
        for (int j = 0; j < m_Width - 1; ++j)
        {
            res += std::to_string(m_Grid[i][j]);
        }
    }    
    return res;
}

std::wstring MazeSolver::serializeSolution()
{
    std::wstring res = L"";
    for (int i = 0; i < m_Height; ++i)
    {
        for (int j = 0; j < m_Width - 1; ++j)
        {
            switch (m_Grid[i][j])
            {
            case 0:
                res += L" ";
                break;
            case 1:
                res += L"█";
                break;
            case 4:
                res += L"x";
                break;
            case 8:
                res += L"S";
                break;
            case 9:
                res += L"E";
                break;
            
            default:
                break;
            }
        }
        res += L"\n";
    }    
    return res;
}

//
// Depth First Search algorithm to solve maze is explained in :
// https://hurna.io/fr/academy/algorithms/maze_pathfinder/dfs.html
//
bool MazeSolver::deepFirstSearch()
{
	m_DfsPathCounter = 0;
	m_DfsStepCounter = 0;
	m_VisitedPositions.assign(m_Height, std::vector<bool>(m_Width - 1, false)); //zero the visited 2D array
    m_VisitedPositions[m_StartingPoint.first][m_StartingPoint.second] = true;
    bool found = false;
    std::stack<std::pair<int, int>> dfs_path_stack;
    dfs_path_stack.push(m_StartingPoint);
    std::map<std::pair<int, int>, std::pair<int, int>> parent;
    // While there is node to be handled in the stack
    while (!dfs_path_stack.empty())
    {
        // Handle the node on the top of the stack and retrieve its unvisited neighbors
        std::pair<int, int> current_position = dfs_path_stack.top();
        dfs_path_stack.pop();
        // Terminate if the goal is reached
        if(current_position == m_EndingPoint)
        {
            found = true;
            break;
        }
        int i = current_position.first;
        int j = current_position.second;
        if (i+1 < m_Height && m_Grid[i + 1][j] == 0 && !m_VisitedPositions[i + 1][j])
        {
            m_VisitedPositions[i + 1][j] = true;
            dfs_path_stack.push(std::make_pair(i+1, j));
            parent[std::make_pair(i+1, j)] = std::make_pair(i, j);
        }
        if (j+1 < m_Width-1 && m_Grid[i][j + 1] == 0 && !m_VisitedPositions[i][j + 1])
        {
            m_VisitedPositions[i][j + 1] = true;
            dfs_path_stack.push(std::make_pair(i, j+1));
            parent[std::make_pair(i, j+1)] = std::make_pair(i, j);
        }
        if (j-1 >= 0 && m_Grid[i][j - 1] == 0 && !m_VisitedPositions[i][j - 1])
        {
            m_VisitedPositions[i][j - 1] = true;
            dfs_path_stack.push(std::make_pair(i, j-1));
            parent[std::make_pair(i, j-1)] = std::make_pair(i, j);
        }
        if (i-1 >= 0 && m_Grid[i - 1][j] == 0 && !m_VisitedPositions[i - 1][j])
        {
            m_VisitedPositions[i - 1][j] = true;
            dfs_path_stack.push(std::make_pair(i-1, j));
            parent[std::make_pair(i-1, j)] = std::make_pair(i, j);
        }
    }
    if(found)
    {
        auto path_point = m_EndingPoint;
        while (path_point!= m_StartingPoint)
        {
            m_Grid[path_point.first][path_point.second] = 4;
            path_point = parent[path_point];
        }
        m_Grid[m_StartingPoint.first][m_StartingPoint.second] = 8;
        m_Grid[m_EndingPoint.first][m_EndingPoint.second] = 9;
    }
    return found;
}
