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

//as floyd's cycle detection algorithm we can use this in array also to find the duplicate value if both stops
// on the same element then array contains duplicate element and we can even return the index of that
int findDuplicate(vector<int>& nums) {
    // first of all we will make two pointers that will iterates through the array 
    int slow = nums[0];
    int fast = nums[0];
    
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast); // we will check until both becomes same
    
    slow = nums[0]; // than we will take one pointer and and put it at start of the array and step ip both pointers
    // with one steps
    while (slow != fast) { //when both gets same again then thats the index where duplicate is present
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow; // both are at same position so we can return either slow or fast;
    // return fast;
}

int main() {
    vector<int> nums{1,3,4,2,2};
    cout << "duplicate : " << findDuplicate(nums) << endl;
}