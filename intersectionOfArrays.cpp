// we are given two arrays which are sorted in non-decreasing order we have to return common elements from
// the two array in optimal solution

//both can have different sizes

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr1{1,2,3};
    vector<int> arr2{3,4};

    // -> non-optimal simple solution time complexity O(N^2).
    // vector<int> ans;
    // for(int i=0;i<arr1.size();i++) {
    //     for(int j=0;j<arr2.size();j++) {
    //         if(arr1[i] == arr2[j]) {
    //             ans.push_back(arr1[i]);
    //             arr2[j] = -1; // so they won't match again and make another pair
    //         }
    //     }
    // }
    // for(int ele: ans) {
    //     cout << ele << ", ";
    // }

    // -> we r taking advantage of the sorted thing, two pointer approach time complexity O(n).
    // in this two pointe approach we will make two pointers and compare things.
    vector<int> ans;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()) {

        if(arr1[i] == arr2[j]) { // if both are same we will push that element into ans vector
            ans.push_back(arr1[i]);
            i++;j++; // and step up both pointers by one
        }
        else if(arr1[i] < arr2[j]) { // if the array 1's value is less than array2's value and we will increase the pointer of the array 1 which is i
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            j++; // same as above we will increase j by one if the array1's element is bigger than array2's value
        }
    }
    for(int ele: ans) {
        cout << ele << ", ";
    }
    return 0;
}