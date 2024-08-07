/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // we will sort the array so all the duplicate elements comes closer
        // so now we will check if two numbers aside are same or not then if same then we will return true 
        // that array contains duplicate values
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};