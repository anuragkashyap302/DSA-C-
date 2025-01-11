#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    void addBoardToResult(const std::vector<std::vector<char>>& board, std::vector<std::vector<std::string>>& ans, int n) {
        std::vector<std::string> temp;
        for (int i = 0; i < n; i++) {
            std::string rowStr;
            for (int j = 0; j < n; j++) {
                rowStr += board[i][j];
            }
            temp.push_back(rowStr);
        }
        ans.push_back(temp);
    }

    void solve(int col, std::vector<std::vector<char>>& board, std::vector<std::vector<std::string>>& ans, int n,
               std::unordered_map<int, bool>& cols, std::unordered_map<int, bool>& diag1, std::unordered_map<int, bool>& diag2) {
        if (col == n) {
            addBoardToResult(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            // Calculate diagonal keys
            int d1 = row - col;
            int d2 = row + col;

            // Check if the column or diagonals are occupied
            if (!cols[row] && !diag1[d1] && !diag2[d2]) {
                // Place queen
                board[row][col] = 'Q';
                cols[row] = diag1[d1] = diag2[d2] = true;  // Mark this column and diagonals as occupied

                // Recurse for the next column
                solve(col + 1, board, ans, n, cols, diag1, diag2);

                // Backtrack: Remove queen and unmark the column and diagonals
                board[row][col] = '.';
                cols[row] = diag1[d1] = diag2[d2] = false;
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::vector<char>> board(n, std::vector<char>(n, '.'));  // Initialize empty 2D board
        std::unordered_map<int, bool> cols;  // Track columns with queens
        std::unordered_map<int, bool> diag1; // Track primary diagonals
        std::unordered_map<int, bool> diag2; // Track secondary diagonals
        solve(0, board, ans, n, cols, diag1, diag2);  // Start solving from column 0
        return ans;
    }
};
int main(){
    
}