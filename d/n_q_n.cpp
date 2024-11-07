#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve N Queens problem
void solveNQueensUtil(int n, int row, vector<int> &board, vector<vector<int>> &solutions)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            solveNQueensUtil(n, row + 1, board, solutions);
            board[row] = -1; // Backtrack
        }
    }
}

// Function to solve N Queens problem
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solveNQueensUtil(n, 0, board, solutions);
    return solutions;
}

int main()
{
    int n = 4;
    vector<vector<int>> solutions = solveNQueens(n);
    for (const auto &solution : solutions)
    {
        for (int col : solution)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}