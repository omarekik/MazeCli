#!/bin/bash

# Build 
mkdir build 
cd build
cmake .. 
make

# Run unit tests
make test 

cd main

# Print help message
./Maze -h 

# Create a maze
./Maze --create --width 10 --height 10 --seed 1234 

# Solve maze
./Maze -c | ./Maze --solve

# Open a bash terminal
bash