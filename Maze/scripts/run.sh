#!/bin/bash

# Build 
mkdir build 
cd build
cmake .. 
make

# Run unit tests
make test 

# Print help message
./maze -h 

# Create a maze
./maze --create --width 10 --height 10 --seed 1234 

# Solve maze
./maze -c | ./maze --solve

# Open a bash terminal
bash