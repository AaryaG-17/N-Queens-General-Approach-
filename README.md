# N-Queens-General-Approach-
The classic way to solve N queens problem

The N-Queen's problem: Place 'N' queens on a 'NxN' chessboard so that no queens are in a position to attack any other queen. That is, any queen on the chessboard should NOT be in the same row, same column, or same diagonal as of any other queens on the chessboard.

This problem is typically solved using **Backtracking**.

Following is the Algorithm:

1. Read the value of N for an N×N chessboard.
2. Create an array board[N] where board[i] stores the column position of the queen placed in row i.
3. Begin placing queens from the first row (row = 0).
4. For the current row, try placing a queen in each column from 0 to N−1.
5. For each position (row, col), check if it is safe by comparing it with all previously placed queens:
#If another queen is in the same column, the position is invalid.
#If another queen lies on the same diagonal, the position is invalid.
6. If the position is safe, place the queen in that column for the current row by storing col in board[row].
7. Move to the next row and repeat the process of trying all column positions.
8. If a row is reached where no column position is safe, move back to the previous row and place the queen in the next available column (backtracking).
9. Continue placing queens and backtracking until either:
#Queens are placed successfully in all N rows, or
#All possibilities have been exhausted.
10. Whenever N queens are successfully placed, store the current configuration as a valid solution.
11. Continue the search to explore all possible placements.
12. After all configurations have been explored, output all stored solutions and the total number of solutions.

**IMPORTANT:** the array board[N], which stores the current combination, stores the values of row and column of a square as follows:

(Assume N = 8 and V = Value) board[8] = {V0, V1, V2, V3, V4, V5, V6, V7} One of the valid combinations of placing 8 quens on a 8x8 chessboard is [(1,4) (2,2) (3,7) (4,3) (5,6) (6,8) (7,5) (8,1)]. This combination will be stored in the array board[8] as: 
board[8] = {4, 2, 7, 3, 6, 8, 5, 1}. That is,
**The array index is the row number and the index value shows the column number.**
