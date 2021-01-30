import numpy as np
def validateGrid(grid,row,col,key):
    subRow = (row // 3) * 3
    subCol = (col // 3) * 3
    for i in range(3):
        for j in range(3):
            if(grid[subRow + i][subCol + j] == key):
                return False
    return True

def valid(grid,row,col,key):
    if(row < len(grid) and col < len(grid)):
        if key not in grid[row] and key not in grid.T[col] and validateGrid(grid,row,col,key):
            return True
        else:
            return False
    return False

def solve(grid):
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                for cell in range(1,10):
                    if valid(grid,i,j,cell):
                        grid[i][j] = cell
                        solve(grid)
                        grid[i][j] = 0 
                return    
    print(grid)
grid= [
            [0, 0, 8, 7, 0, 6, 2, 0, 0],
            [0, 0, 7, 0, 1, 0, 3, 0, 0],
            [0, 0, 0, 4, 0, 0, 0, 0, 0],
            [3, 0, 0, 0, 0, 0, 6, 0, 9],
            [0, 6, 0, 0, 7, 0, 0, 5, 0],
            [1, 0, 5, 0, 0, 0, 0, 0, 2],
            [0, 0, 0, 0, 0, 7, 0, 0, 0],
            [0, 0, 1, 0, 6, 0, 8, 0, 0],
            [0, 0, 4, 2, 0, 5, 7, 0, 0],
]
solve(np.array(grid))