#include <iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        for(int i = 3; i <= n; ++i){
            int t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t2;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = solution.tribonacci(n);
    cout << "The " << n << "th Tribonacci number is: " << result << endl;

    return 0;
}
