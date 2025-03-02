#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[1005][1005];
    string s, t;
    
    int solve(int i, int j) {
        if (i == s.size() || j == t.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (s[i] == t[j]) ans = 1 + solve(i + 1, j + 1);
        else ans = max(solve(i + 1, j), solve(i, j + 1));
        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        s = text1;
        t = text2;
        return solve(0, 0);
    }
};

int main() {
    Solution solution;
    
    string text1 = "abcde";
    string text2 = "ace";
    
    int result = solution.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence Length: " << result << endl;
    
    return 0;
}
