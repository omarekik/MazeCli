#include "StartupConfig.h"

#include <iostream>

#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[])
{
    bpo::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "display help menu")
        ("create,c", bpo::bool_switch(), 
            "output a solvable maze to the terminal containing both start and end points")
        ("width,w", bpo::value<int>() -> default_value(10), "width of the maze to be created")
        ("height,t", bpo::value<int>() -> default_value(10), "height of the maze to be created")
        ("seed,s", bpo::value<int>() -> default_value(10), "seed of the maze to be created")
        ("solve,x", bpo::bool_switch(), "parse the input maze from the terminal and print it back solved. "
                                        "If an impossible maze is given, impossible message will be printed");

    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return std::nullopt;
    }

    return StartupConfig{ vm["create"].as<bool>()
                        , vm["width"].as<int>() 
                        , vm["height"].as<int>() 
                        , vm["seed"].as<int>() 
                        , vm["solve"].as<bool>() 
                        };
}
