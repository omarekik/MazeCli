#include <boost/program_options.hpp>
#include <iostream>

namespace bpo = boost::program_options;

int main(int argc, char* argv[])
{
    try {
        bool create = false;
        int width = 10;
        int height = 10;
        float seed = 10.0f;
        bool solve = false;
        
        bpo::options_description desc("Program options");
        desc.add_options()
        // First parameter describes option name/short name
        // The second is parameter to option
        // The third is description
        ("help,h", "display help menu")
        ("create,c", bpo::value<bool>(&create), 
            "output a solvable maze to the terminal containing both start and end points")
        ("width,w", bpo::value<int>(&width) -> default_value(10), "width of the maze to be created")
        ("height,w", bpo::value<int>(&height) -> default_value(10), "height of the maze to be created")
        ("seed,w", bpo::value<float>(&seed) -> default_value(10.0f), "seed of the maze to be created")
        ("solve,x", bpo::value<bool>(&solve), 
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
        if(!create)
        {
            std::cout << "Warning the maze to be solved should be passed in terminal.\n";
        }
        else
        {
            //
            // TODO : create a solvable maze
            //
        }
        if(solve)
        {
            // TODO : solve maze
        }
    }
    catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}