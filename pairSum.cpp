// in this question we are given arr, where we have to return the elements whose sum is 's'(which is given) and store it into new vector and store all that vector into another vector.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector < vector<int> > ans;
    vector <int> arr = {1,2,3,4,5};
    int s;
    cout << "Enter S :";
    cin >> s;

    for(int i=0;i<arr.size()-1;i++) {
        for(int j=0;j<arr.size();j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(), ans.end());
    // for(int i=0;i<ans.size();i++) {
    //     cout << ans[i] << ", ";
    // }
    return ans;
    
    return 0;
}