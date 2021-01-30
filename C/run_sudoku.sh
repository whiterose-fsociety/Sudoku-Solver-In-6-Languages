#!/bin/bash

filename="sudoku_solver"
if [ -e $filename ]
then 
make clean
fi
echo "Running Make Files"
make
./$filename