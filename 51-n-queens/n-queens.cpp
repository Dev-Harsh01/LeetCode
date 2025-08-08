#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if a queen can be placed at board[row][col]
    bool isSafe(const vector<string>& board, int row, int col, int n) {
        // We only need to check the current column and the two diagonals
        // in the rows above the current row.

        // Check the column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    
    // Recursive backtracking function
    void placeQ(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        // Base case: if all queens are placed successfully (we've filled all rows)
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col, n)) {
                // Place the queen
                board[row][col] = 'Q';
                
                // Recur for the next row
                placeQ(board, row + 1, n, ans);
                
                // Backtrack: remove the queen
                board[row][col] = '.';
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        // Initialize an empty chessboard of size n x n
        vector<string> board(n, string(n, '.'));
        
        // Start the backtracking process from the first row (row 0)
        placeQ(board, 0, n, ans);

        return ans;
    }
};

// Main function for demonstration (optional, but good for testing)