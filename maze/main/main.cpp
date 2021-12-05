#include <iostream>
#include <locale>
#include "MazeGenerator.h"
#include "MazeSolver.h"
#include "StartupConfig.h"

int main(int argc, char* argv[])
{
    try 
    {
        std::ios_base::sync_with_stdio(false);
        std::wcin.imbue(std::locale("en_US.UTF-8"));
        std::wcout.imbue(std::locale("en_US.UTF-8"));

        if (const auto config = optionsToStartupConfig(argc, argv)) 
        {
            if (!(config->m_Create || config->m_Solve))
            {
                std::cout << "Either create or solve option should be called\n";
            }

            if(config->m_Create)
            {
                MazeGenerator maze = MazeGenerator(config->m_Height, config->m_Width, config->m_Seed);
                maze.kruskal();
                std::cout << maze.serialize();
            }
            else
            {
                std::cout << "Warning the maze to be solved should be passed in terminal.\n";
            }

            if(config->m_Solve)
            {
                std::wstring line;
                std::wstring input = L"";

                while(std::getline(std::wcin,line))
                {
                    input += line;
                    input += L"\n";
                }  

                MazeSolver maze = MazeSolver(input);
                if(maze.deepFirstSearch())
                {
                    std::wcout<< maze.serializeSolution();
                }
                else
                {
                    std::cout<<"The given maze is not solvable!\n";
                }
            }
        }
    }
    catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}