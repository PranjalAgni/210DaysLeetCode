/*
Implement Trie (Prefix Tree)


Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

// O(N) & O(N) solution

class TrieNode {
   public:
    unordered_map<char, TrieNode*> hashMap;
    bool isEnd;

    TrieNode() {
        hashMap = unordered_map<char, TrieNode*>();
        isEnd = false;
    }

    bool isPresent(char ch) {
        if (hashMap.find(ch) != hashMap.end()) return true;
        return false;
    }

    TrieNode* getNode(char ch) {
        return hashMap[ch];
    }

    void addNode(char ch, TrieNode* newNode) {
        hashMap[ch] = newNode;
    }

    bool isLast() {
        return isEnd;
    }

    void setLast(bool last) {
        isEnd = last;
    }
};

class Trie {
   public:
    TrieNode* root = NULL;
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->isPresent(ch)) {
                TrieNode* new_node = new TrieNode();
                current->addNode(ch, new_node);
            }
            current = current->getNode(ch);
        }

        current->setLast(true);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->isPresent(ch)) return false;
            current = current->getNode(ch);
        }

        return current->isLast();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (!current->isPresent(ch)) return false;
            current = current->getNode(ch);
        }

        return true;
    }
};