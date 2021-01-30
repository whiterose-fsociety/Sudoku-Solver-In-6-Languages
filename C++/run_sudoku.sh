#!/bin/bash

filename="Sudoku_Solver"
if [ -e $filename ]
then 
make clean
fi
echo "Running Make Files"
make
echo ""
./$filename