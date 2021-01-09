/*
Word Ladder

Solution
Given two words beginWord and endWord, and a dictionary wordList, return the
length of the shortest transformation sequence from beginWord to endWord, such
that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: As one shortest
transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its
length 5. Example 2:

Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is not
in wordList, therefore no possible transformation.


Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

// BFS Graph solution
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> ourmap;
        bool found = false;

        for (auto w : wordList) {
            if (endWord == w) found = true;

            ourmap.insert(w);
        }

        if (!found) return 0;

        queue<string> pendingNodes;
        pendingNodes.push(beginWord);
        int level = 0;

        while (pendingNodes.size() != 0) {
            level++;
            int size = pendingNodes.size();

            for (int i = 0; i < size; i++) {
                string current = pendingNodes.front();
                pendingNodes.pop();

                for (int j = 0; j < current.size(); j++) {
                    string temp = current;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;

                        if (temp == current)
                            continue;

                        else if (endWord == temp)
                            return level + 1;

                        else if (ourmap.find(temp) != ourmap.end()) {
                            pendingNodes.push(temp);
                            ourmap.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};