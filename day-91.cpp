/*
  Word Search II


Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
*/

// Trie + DFS based solution
class Trie {
   public:
    Trie* children[26];
    bool endOfWord;

    Trie() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(string word) {
        Trie* curr = this;

        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) curr->children[index] = new Trie();
            curr = curr->children[index];
        }

        curr->endOfWord = true;
    }
};

class Solution {
   public:
    void dfs(vector<vector<char>>& board, int i, int j, unordered_set<string>& result, Trie* trie, string forming) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] != '$') {
            char curr = board[i][j];

            board[i][j] = '$';

            Trie* currTrie = trie->children[curr - 'a'];

            if (currTrie) {
                string newForming = forming + curr;
                if (currTrie->endOfWord) result.insert(newForming);

                dfs(board, i - 1, j, result, currTrie, newForming);
                dfs(board, i + 1, j, result, currTrie, newForming);
                dfs(board, i, j - 1, result, currTrie, newForming);
                dfs(board, i, j + 1, result, currTrie, newForming);
            }

            board[i][j] = curr;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0) return {};

        Trie trie;

        for (string word : words) trie.insert(word);

        unordered_set<string> result;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, result, &trie, "");
            }
        }

        vector<string> answer(result.begin(), result.end());

        return answer;
    }
};