/*
  Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

// DFS based solution O(rows x cols)
class Solution {
   public:
    void doDFS(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == 'X' || board[row][col] == 'A') return;

        board[row][col] = 'A';
        doDFS(board, row - 1, col);
        doDFS(board, row + 1, col);
        doDFS(board, row, col - 1);
        doDFS(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows <= 2) return;
        int cols = board[0].size();
        if (cols <= 2) return;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)) doDFS(board, i, j);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};