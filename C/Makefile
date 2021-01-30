output:	sudoku.o program.o
	gcc sudoku.o program.o -o sudoku_solver -lm

program.o: program.c
	gcc -c program.c	

sudoku.o: sudoku.c sudoku.h
	gcc -c sudoku.c -lm

clean:
	rm *.o sudoku_solver