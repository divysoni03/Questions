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

//for first and last occurrence we can do two loop that iterates through array from beginning and one from end
// but this algo will have O(n) time complexity.

// so we can use binary search for that so we can solve this will O(lon n ) time complexity.
int firstOccurrence(vector<int> &nums, int target) {
    //starting with simple binary search initialization
    int n = nums.size(), start = 0, end = n-1, ans = -1; 
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(nums[mid]==target) {
            ans = mid; // now instead of returning mid we will store the value in ans var 
            // and we will check if ahead of the mid that any other occurrence are there or not 
            // so we will change out end to left side of the mid and we will check in that area if the new occurrence found 
            // we will store that unless after ending of the loop we will return the ans which will be the first occurrence
            end = mid-1;
        }
        else if(nums[mid] < target) {
            start = mid+1; //if mid is less than target then we will change our start to mid+1.
        }
        else if(nums[mid] > target) {
            end = mid-1; // same as above if mid is less than target than we will change it to mid-1.
        }
        mid = start + (end-start)/2; // after each iteration we have to change the mid or we can say update the mid.
    }
    return ans;
}

int lastOccurrence(vector<int> &nums, int target) {
    int n = nums.size(), start = 0, end = n-1,ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(nums[mid]==target) {
            ans = mid; // as the first occurrence, now we have to search the last occurrence so we will check
            // right side after finding one occurrence we will store that occurrence in ans.
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