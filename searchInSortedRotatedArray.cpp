/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1
*/
int getPivot(vector<int> nums, int target, int n) {
    int s=0,e=n-1;
    int mid = s + (e-s)/2;
    while(s < e) {
        if(nums[mid] >= nums[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch(vector<int> nums, int s, int e, int target) {
    int mid = s + (e-s)/2;
    while(s <= e) {
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            s = mid+1;
        }
        else if(nums[mid] > target) {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), pivot = getPivot(nums, target, n);

        if(target >= nums[pivot] && target <= nums[n-1]) {
            return binarySearch(nums, pivot, n-1, target);
        }
        else {
            return binarySearch(nums, 0, pivot-1, target);
        }
    }
};