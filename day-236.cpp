/*
  Unique Morse Code Words


International Morse Code defines a standard encoding where each letter is mapped
to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to
"-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is
given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the
Morse code of each letter. For example, "cab" can be written as "-.-..--...",
(which is the concatenation "-.-." + ".-" + "-..."). We'll call such a
concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.

*/

// Solution using hashMap to store frequency of codes
// and return only unique number of codes
// TC: O(len(words) * len(word)) = O(N * n)

class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode{".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                                 "--.",  "....", "..",   ".---", "-.-",  ".-..",
                                 "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                                 "...",  "-",    "..-",  "...-", ".--",  "-..-",
                                 "-.--", "--.."};

        int N = words.size();
        unordered_map<string, int> morseCodeFreq;

        int uniqueCode = 0;

        for (int idx = 0; idx < N; idx++) {
            string word = words[idx];
            string result = "";
            for (char ch : word) {
                int pos = (ch & 31);
                result += morseCode[pos - 1];
            }

            morseCodeFreq[result] += 1;
            if (morseCodeFreq[result] == 1) uniqueCode += 1;
        }

        return uniqueCode;
    }
};