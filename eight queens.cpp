#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<int>> solutions;

bool isSafe(vector<int>& board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col) return false; // same column

        if (abs(board[i] - col) == abs(i - row)) return false; // same diagonal
    }
    return true;
}

void placeQueen(vector<int>& board, int row)
{
    if (row == N)
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            placeQueen(board, row + 1);
        }
    }
}

int main()
{
    while (true)
    {
        cout << "Enter value of 'N' for a NxN chessboard: ";

        if (!(cin >> N))
        {
            cout << "Error: Input must be an integer.\n"; //Inut validation for invalid input of N

            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        if (N <= 0)
        {
            cout << "Error: Enter a positive value of N.\n"; //Inut validation for negative input of N
            continue;
        }

        if (N > 12)
        {
            cout << "Error: Number too high. Enter N ≤ 12.\n"; //The value of N is restricted to 12 as total combinations for N>=13 are too much for calculating.
            continue;
        }

        break;
    }

    vector<int> board(N);

    placeQueen(board, 0);

    int count = 1;

    for (vector<int>& sol : solutions)
    {
        cout << "Solution " << count++ << ":\n";

        for (int i = 0; i < N; i++)
        {
            cout << "(" << i + 1 << "," << sol[i] + 1 << ") ";
        }

        cout << "\n\n";
    }

    cout << "Total solutions: " << solutions.size() << endl;

    return 0;
}
