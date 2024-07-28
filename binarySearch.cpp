class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(),start=0,end=len-1,mid = len/2;
        while(start <= end) {
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                start = mid+1;
                mid = (start + end)/2;
            }
            else if(nums[mid] > target) {
                end = mid-1;
                mid = (start + end)/2;
            }
        }
        return -1;
    }
};