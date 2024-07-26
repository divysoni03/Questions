// sort zero one and twos from array in non-decreasing order.
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
   int temp = a;
   a = b;
   b = temp;
}
void sort012(int *arr, int n) {
  int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    // all test cases
    int arr[] = {0, 1, 2, 2, 1, 0};
    // int arr[] = {0, 1, 2, 1, 2, 1, 2};
    // int arr[] = {2, 2, 2, 1, 1, 1, 0};
    // int arr[] = {2, 1, 2, 0, 1, 0};
    
    //size
    int n = sizeof(arr)/sizeof(arr[0]);

    sort012(arr, n);
    for(int ele : arr) {
        cout << ele << ", ";
    }
}