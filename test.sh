#!/bin/bash

echo "Directory to run tests on? "
read imp
cd $imp
g++ -o main main.cpp
cat input.txt | valgrind ./main
rm main
cd ..
