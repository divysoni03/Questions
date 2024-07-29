/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1] 
*/

int firstOccurrence(vector<int> &nums, int target) {
    int n = nums.size(), start = 0, end = n-1, ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(nums[mid]==target) {
            ans = mid;
            end = mid-1;
        }
        else if(nums[mid] < target) {
            start = mid+1;
        }
        else if(nums[mid] > target) {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int lastOccurrence(vector<int> &nums, int target) {
    int n = nums.size(), start = 0, end = n-1,ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(nums[mid]==target) {
            ans = mid;
            start = mid+1;
        }
        else if(nums[mid] < target) {
            start = mid+1;   
        }
        else if(nums[mid] > target) {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccurrence(nums, target));
        ans.push_back(lastOccurrence(nums, target));

        return ans;
    }
};