#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1001] = {};
    
    int numTilings(int n) {
        if (n <= 2) return n;
        if (n == 3) return 5;
        return dp[n] ? dp[n] : dp[n] = ((numTilings(n - 1) * 2) % mod + (numTilings(n - 3)) % mod) % mod;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of ways to tile a " << n << "x2 board: " << sol.numTilings(n) << endl;
    return 0;
}