#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = (i % 2) + dp[i / 2];
        }
        return dp;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> result = sol.countBits(n);
    
    cout << "Count of bits up to " << n << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}