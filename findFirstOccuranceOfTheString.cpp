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
public: // so here we have to find the first occurrence of the given needle or we can say that it is a
// sub- string of the main haystack(main string)
    int strStr(string haystack, string needle) {
        //return haystack.find(needle); // we can just use inbuilt function to return the index of the first occurrence of the substr
        // int pos = haystack.find(needle);
        // if(pos != string::npos) return pos;
        
        // without any inbuilt search function we can search by this way that 
        // we already know that needle is sub part of the haystack or main string and it can repeat many times
        // so we will extract substr from main string size of needle and we will check that substr with the 
        // needle if both are same we can return the starting index
        int n = needle.size();
        for(int i=0;i<haystack.length();i++) {
            if((haystack.substr(i,n))== needle) return i;
        }
        return -1;
    }
};