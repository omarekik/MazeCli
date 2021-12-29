#!/bin/bash

# Build & Run unit tests & create conan package
conan create . 

# Install conan package
mkdir run_linux
cd run_linux
conan install maze/0.1.0@ -g virtualrunenv 

# Start testing conan package
source activate_run.sh

# Print help message
Maze -h 

# Create a maze
Maze --create --width 10 --height 10 --seed 1234 

# Solve maze
Maze -c | Maze --solve

# Remain CLI open to play more with it
bash

# Exit or finish testing conan package 
# source deactivate_run.sh