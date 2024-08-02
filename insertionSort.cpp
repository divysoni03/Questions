#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // for(int i=1; i<n; i++) {
    //     int temp = arr[i],j=i-1;
    //     for (; j >= 0; j--) {
    //       if (arr[j] > temp) {
    //           arr[j+1] = arr[j];
    //       }
    //       else break;
    //     }
    //     arr[j+1] = temp;
    // }
    for(int i=1; i<n; i++) {
        int temp = arr[i], j=i-1;
        while(j >= 0) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else break;
            j--;
        }
        arr[j+1] = temp;
    }
}