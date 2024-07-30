/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

*/

class Solution {
public:
    long long int mySqrt(int x) {
        int start=0, end = x, ans = -1;

        long long int mid = start + (end-start)/2;
        
        if(x == 0) return 0;
        while(start <= end) {
            long long int square = mid*mid;
            if(square == x) {
                return mid;
            }

            if(square < x) {
                ans = mid; //temp ans or rounded ans
                start = mid+1;
            }
            else {
                end = mid -1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
};