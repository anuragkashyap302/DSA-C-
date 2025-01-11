// #include <unordered_map>
// #include <vector>
// #include <string>

// class Solution{
// public:
//     bool issafe(int row, int col, vector<vector<char>>& board, int n) {
//         // Check for queen in the same row
//         for (int j = 0; j < col; j++) {
//             if (board[row][j] == 'Q') return false;
//         }
//         // Check for queen on upper left diagonal
//         for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//             if (board[i][j] == 'Q') return false;
//         }
//         // Check for queen on lower left diagonal
//         for (int i = row, j = col; i < n && j >= 0; i++, j--) {
//             if (board[i][j] == 'Q') return false;
//         }
//         return true;
//     }

//     void addBoardToResult(vector<vector<char>>& board, vector<vector<string>>& ans, int n) {
//         vector<string> temp;
//         for (int i = 0; i < n; i++) {
//             string rowStr;
//             for (int j = 0; j < n; j++) {
//                 rowStr += board[i][j];  // Add each character to rowStr
//             }
//             temp.push_back(rowStr);  // Add the row string to temp
//         }
//         ans.push_back(temp);  // Add temp to ans
//     }

//     void solve(int col, vector<vector<char>>& board, vector<vector<string>>& ans, int n) {
//         if (col == n) {
//             addBoardToResult(board, ans, n);  // Use helper function to add board to ans
//             return;
//         }

//         for (int row = 0; row < n; row++) {
//             if (issafe(row, col, board, n)) {
//                 board[row][col] = 'Q';  // Place queen
//                 solve(col + 1, board, ans, n);  // Recurse to place queen in the next column
//                 board[row][col] = '.';  // Backtrack
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<vector<char>> board(n, vector<char>(n, '.'));  // Initialize empty 2D board
//         solve(0, board, ans, n);  // Start solving from column 0
//         return ans;
//     }
// };
// int main(){
//    vector<vector<string>>ans =vector<vector<string>>solveNQueens;

// }