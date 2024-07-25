// In the given array all the numbers occurs twice find the unique number which occurs once.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{2,7,3,1,3,2,7}; // 1 occurs only once so output will be 1.
    int ans =0;
    for(int i=0;i<arr.size();i++) {
        ans ^= arr[i];
    }
    cout << "Unique number :" << ans << endl;
    return 0;
}