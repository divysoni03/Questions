#include <iostream>
using namespace std;

long long int mySqrt(int x) {
    int start=0, end = x, ans = -1;
    long long int mid = start + (end-start)/2;
    
    if(x == 0) return 0;
    while(start <= end) {
        long long int square = mid*mid;
        if(square == x) {
            return mid;
        }
        if(square < x) {
            ans = mid; //temp ans or rounded ans
            start = mid+1;
        }
        else {
            end = mid -1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
double morePrecision(int x, int precision, int tempSolution) {
    double ans = tempSolution;
    double factor = 1;
    for(int i=0;i<precision;i++) {
        factor /=10;
        for(double j=tempSolution;j*j<=x;j+=factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int num,precision;
    cout << "Enter a number :";
    cin >> num;
    cout << "Enter Precision :";
    cin >> precision;
    int temp = mySqrt(num);
    cout << "Entered number :" << num << "\nfinal ans :" << morePrecision(num, precision, temp) << endl;
}