/*
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3


Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.


Sample Input 2 :
5 2
4 2 1 3 6


Sample Output 2 :
5


Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?


Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.
*/

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cows = 1, lastPosition = stalls[0];
    for(int i=0;i<stalls.size(); i++) {
        if(stalls[i]-lastPosition >=mid) {
            cows++;
            if(cows==k) return true;
            else lastPosition = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    if(stalls.size() < k) return -1; 

    sort(stalls.begin(), stalls.end());
    int s = 0, e = -1,ans = -1;

    for(int i=0; i< stalls.size(); i++) {
        if(e < stalls[i]) {
            e = stalls[i];
        }
    }

    int mid = s + (e-s)/2;

    while(s <= e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid +1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}