/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
        for(int i=0;i<haystack.length();i++) {
            // int pos = haystack.find(needle);
            // if(pos != string::npos) return pos;
            int n = needle.size();
            if((haystack.substr(i,n))== needle) return i;
        }
        return -1;
    }
};