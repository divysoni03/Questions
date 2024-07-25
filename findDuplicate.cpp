/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3

Input: nums = [3,3,3,3,3]
Output: 3
*/

//Floyd's Tortoise and Hare algorithm 
// youtube video for more explanation -> https://youtu.be/S5TcPmTl6ww?si=PYb4YtD2NHpqLnUc
 
#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

int main() {
    vector<int> nums{1,3,4,2,2};
    cout << "duplicate : " << findDuplicate(nums) << endl;
}