/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
       long long reverse = 0;
       if(x<0) {
        while(x<0) {
            reverse *= 10;
            reverse -= x%10;
            x /= 10;
        }
        reverse *= -1;
       }
       else {
        while(x>0) {
            reverse = (reverse*10)+(x%10);
            x /=10;
        }
       }
        if(reverse >= 2147483648 || reverse <= -2147483648) return 0;
        else return reverse;
    }
};