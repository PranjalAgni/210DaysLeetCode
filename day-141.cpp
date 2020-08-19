/*
  Goat Latin


A sentence S is given, composed of words separated by spaces. Each word consists
of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language
similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the
word. For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter
and append it to the end, then add "ma". For example, the word "goat" becomes
"oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence,
starting with 1. For example, the first word gets "a" added to the end, the
second word gets "aa" added to the end and so on. Return the final sentence
representing the conversion from S to Goat Latin.
*/

// Simple O(N) solution. Doing string manipulation
class Solution {
   public:
    bool isVowel(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    string toGoatLatin(string S) {
        const string POSTFIX = "ma";
        const char SPACE = ' ';
        const string EMPTY_STRING = "";

        int N = S.size();
        string result = EMPTY_STRING;
        string letterA = EMPTY_STRING;
        for (int idx = 0; idx < N; idx++) {
            string current = EMPTY_STRING;
            bool isFirstChar = true;
            char ifConsonant = '@';

            while (S[idx] != SPACE) {
                if (isFirstChar) {
                    isFirstChar = false;
                    if (!isVowel(S[idx])) {
                        ifConsonant = S[idx];
                        idx += 1;
                        if (idx == N) break;
                        continue;
                    }
                }
                current += S[idx];
                idx += 1;
                if (idx == N) break;
            }

            letterA += 'a';

            if (ifConsonant != '@') current += ifConsonant;

            result += current + POSTFIX + letterA;
            if (idx != N) result += SPACE;
        }

        return result;
    }
};