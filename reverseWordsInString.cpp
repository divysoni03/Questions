/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for(int i = 0; i <= s.length(); ++i) {
            if(i == s.length() || s[i] == ' ') {
                if(!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }

        string ans = "";
        for(int i = words.size() - 1; i >= 0; --i) {
            ans += words[i];
            if(i > 0) ans += ' ';
        }
        return ans;
    }
};