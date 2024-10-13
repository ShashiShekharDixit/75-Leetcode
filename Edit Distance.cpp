class Solution {
public:
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if(i>=s1.size())
         return s2.size()-j;
        if(j>=s2.size())
            return s1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=f(i+1,j+1,s1,s2,dp);
        int a=1+f(i,j+1,s1,s2,dp);
        int b=1+f(i+1,j,s1,s2,dp);
        int c=1+f(i+1,j+1,s1,s2,dp);
        return dp[i][j]=min({a,b,c});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,word1,word2,dp);
    }
};