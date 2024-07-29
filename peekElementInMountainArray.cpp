/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(), start=0, end = n-1;
        int mid = start + (end - start)/2;
        while(start < end) {
            if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1] && mid+1< n) {
                return mid;
            }
            else if(arr[mid]<arr[mid+1] && mid+1<n) {
                start = mid+1;
            }
            else end = mid;
            mid = start + (end - start)/2;
        }
        return -1;
    }
};