// swap alternates values from array or vector
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,7,8,4,5}; // even size
    // int arr[] = {1,2,7,8,4}; // odd size
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i+=2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    
    for(int ele : arr) {
        cout << ele << ", ";
    }
    return 0;
}