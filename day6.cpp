/*
Question: Given an array of strings, group anagrams together.
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); i++) {
            string strCopy = strs[i];
            sort(strs[i].begin(), strs[i].end());
            hashMap[strs[i]].push_back(strCopy);
        }

        for (auto& itr : hashMap) {
            answer.push_back(itr.second);
        }
        return answer;
    }
};