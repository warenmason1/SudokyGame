#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 9;

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool checkCol(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool checkBox(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    return !checkRow(grid, row, num) &&
           !checkCol(grid, col, num) &&
           !checkBox(grid, row - row % 3, col - col % 3, num);
}

bool findUnassigned(int grid[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    if (!findUnassigned(grid, row, col)) {
        return true;
    }
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void generateRandomPuzzle(int grid[SIZE][SIZE]) {
    srand(time(0));
    int numOfRemoved = rand() % 20 + 30;
    while (numOfRemoved) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            numOfRemoved--;
        }
    }
}
