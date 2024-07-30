// In the given array all the numbers occurs twice find the unique number which occurs once.
#include <iostream>
#include <vector>
using namespace std;

// here in the question we are given an array which have every element twice unless one element so we have to return 
// that unique element
int main() {
    vector<int> arr{2,7,3,1,3,2,7}; // 1 occurs only once so output will be 1.

    // we will use XOR bit manipulation technique for that, as we know about xor property that it will return 0 if both inputs are same
    // so 1 ^ 1 = 0.
    int ans =0;
    for(int i=0;i<arr.size();i++) {
        ans ^= arr[i]; //we will xor all the elements in the ans var and all the twice number will become zero eventually.
    }
    cout << "Unique number :" << ans << endl;
    return 0;
}