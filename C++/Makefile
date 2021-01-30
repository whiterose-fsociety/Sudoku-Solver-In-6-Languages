output: Sudoku.o Sudoku_Solver.o Grid.o
	g++ Sudoku.o Sudoku_Solver.o Grid.o -o Sudoku_Solver -lm

Sudoku_Solver.o: Sudoku_Solver.cpp
	g++ -c Sudoku_Solver.cpp

Soduku.o: Soduku.cpp Sodoku.h
	g++ -c Sodoku.cpp -lm

Grid.o: Grid.cpp Grid.h
	g++ -c Grid.cpp -lm

clean:
	rm *.o Sudoku_Solver