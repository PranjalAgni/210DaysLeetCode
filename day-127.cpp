/*
  Add and Search Word - Data structure design



Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing
only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

// Solved using trie

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    vector<WordDictionary*> children;
    bool isEndOfWord;
    WordDictionary() {
        children = vector<WordDictionary*>(26, NULL);
        isEndOfWord = false;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* current = this;
        for (char c : word) {
            if (current->children[c - 'a'] == NULL) {
                current->children[c - 'a'] = new WordDictionary();
            }

            current = current->children[c - 'a'];
        }

        current->isEndOfWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary* current = this;
        for (int idx = 0; idx < word.length(); idx++) {
            char curr = word[idx];
            if (curr == '.') {
                for (auto child : current->children) {
                    if (child && child->search(word.substr(idx + 1)))
                        return true;
                }

                return false;
            }

            if (current->children[curr - 'a'] == NULL) return false;
            current = current->children[curr - 'a'];
        }

        return current && current->isEndOfWord;
    }
};
