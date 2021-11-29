#include <boost/program_options.hpp>
#include <iostream>
#include <locale>
#include <regex>
#include "MazeGenerator.h"
#include "MazeSolver.h"

namespace bpo = boost::program_options;

int main(int argc, char* argv[])
{
    try 
    {
        std::ios_base::sync_with_stdio(false);
        std::wcin.imbue(std::locale("en_US.UTF-8"));
        std::wcout.imbue(std::locale("en_US.UTF-8"));

        bool create = false;
        int width = 10;
        int height = 10;
        int seed = 10;
        bool solve = false;
        
        bpo::options_description desc("Program options");
        desc.add_options()
        // First parameter describes option name/short name
        // The second is parameter to option
        // The third is description
        ("help,h", "display help menu")
        ("create,c", bpo::bool_switch(&create), 
            "output a solvable maze to the terminal containing both start and end points")
        ("width,w", bpo::value<int>(&width) -> default_value(10), "width of the maze to be created")
        ("height,t", bpo::value<int>(&height) -> default_value(10), "height of the maze to be created")
        ("seed,s", bpo::value<int>(&seed) -> default_value(10), "seed of the maze to be created")
        ("solve,x", bpo::bool_switch(&solve), 
            "parse the input maze from the terminal and print it back solved. "
            "If an impossible maze is given, impossible message will be printed")
        ;
    
        bpo::variables_map options_map;
        bpo::store(bpo::parse_command_line(argc, argv, desc), options_map);
        bpo::notify(options_map);

        if (options_map.count("help") || !(create || solve)) 
        {  
            std::cout << desc << "\n";
            if (!(create || solve))
            {
                std::cout << "Either create or solve option should be called\n";
            }
            return 0;
        }
        if(create)
        {
            MazeGenerator maze = MazeGenerator(height, width, seed);
            maze.kruskal();
            std::cout << maze.serialize();
        }
        else
        {
            std::cout << "Warning the maze to be solved should be passed in terminal.\n";
        }
        if(solve)
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
    catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}