#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solveTabulation(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int first = 0, second = 0;
                if (i > 0)
                    first = dp[i - 1][j];
                if (j > 0)
                    second = dp[i][j - 1];
                dp[i][j] = first + second;
            }
        }
        return dp[m][n];
    }

public:
    int uniquePaths(int m, int n) {
        return solveTabulation(m - 1, n - 1);
    }
};

int main() {
    Solution solution;

    int m1 = 3, n1 = 7;
    cout << "Unique Paths (Grid: 3x7): " << solution.uniquePaths(m1, n1) << endl;

    int m2 = 3, n2 = 2;
    cout << "Unique Paths (Grid: 3x2): " << solution.uniquePaths(m2, n2) << endl;

    int m3 = 1, n3 = 1;
    cout << "Unique Paths (Grid: 1x1): " << solution.uniquePaths(m3, n3) << endl;

    return 0;
}
