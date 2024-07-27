/*
Given an integer x, return true if x is a 
palindrome
and false otherwise.

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse=0;
        int num = x;
        if(x<0) return 0;
        while(num!=0){
            reverse = (reverse*10) + (num%10);
            num/=10;
        }
        return (reverse==x) ? true : false;
    }
};