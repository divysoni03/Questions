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
    vector<int> ans;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()) {

        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            j++;
        }
    }
    for(int ele: ans) {
        cout << ele << ", ";
    }
    return 0;
}