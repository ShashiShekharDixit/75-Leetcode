class Solution {
public:
    int dp[1005][1005];
    string s, t;
    int solve(int i, int j) {
        if(i == s.size() or j == t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]) ans = 1 + solve(i + 1, j + 1);
        else ans = max(solve(i + 1, j), solve(i, j + 1));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp , -1, sizeof(dp));
        s = text1;
        t = text2;
        int ans = solve(0, 0);
        return ans;
    }
};