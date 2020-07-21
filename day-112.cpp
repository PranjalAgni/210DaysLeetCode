/*
  Word Search


Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

// DFS approach beats 95% of cpp solution
class Solution {
   public:
    bool isValidIndex(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();

        if ((row >= 0 && row < rows) && (col >= 0 && col < cols)) return true;
        return false;
    }

    bool searchInGrid(vector<vector<char>>& board, int row, int col, string& word, int idx) {
        if (idx == word.length() - 1) return true;

        if (!isValidIndex(board, row, col) || (word[idx] != board[row][col])) return false;

        char temp = board[row][col];
        board[row][col] = '$';

        if (isValidIndex(board, row, col - 1) && board[row][col - 1] == word[idx + 1] && searchInGrid(board, row, col - 1, word, idx + 1)) return true;

        if (isValidIndex(board, row, col + 1) && board[row][col + 1] == word[idx + 1] && searchInGrid(board, row, col + 1, word, idx + 1)) return true;

        if (isValidIndex(board, row - 1, col) && board[row - 1][col] == word[idx + 1] && searchInGrid(board, row - 1, col, word, idx + 1)) return true;

        if (isValidIndex(board, row + 1, col) && board[row + 1][col] == word[idx + 1] && searchInGrid(board, row + 1, col, word, idx + 1)) return true;

        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char startCharacter = word[0];

        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if ((board[row][col] == startCharacter) && searchInGrid(board, row, col, word, 0)) return true;
            }
        }

        return false;
    }
};