class Solution {
private:
    int solveTabulation(int m, int n){
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
               if(i == 0 && j == 0)
               {
                dp[i][j] = 1;
                continue;
               }
               int first = 0, second = 0;
               if(i > 0)
               first = dp[i - 1][j];
               if(j > 0)
               second = dp[i][j - 1];
               dp[i][j] = first + second;
            }
        }
        return dp[m][n];
    }
public:
    int uniquePaths(int m, int n) {
        int ans = solveTabulation(m - 1, n - 1);
        return ans;
    }
};