#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int>& prices, int index, bool hold, int fee, vector<vector<int>>& dp) {
        if (index == prices.size()) return 0;

        if (!hold) {
            if (dp[index][0] != -1) return dp[index][0];
            int buy = -prices[index] + helper(prices, index + 1, true, fee, dp);
            int wait = helper(prices, index + 1, hold, fee, dp);
            dp[index][0] = max(buy, wait);
            return dp[index][0];
        } else {
            if (dp[index][1] != -1) return dp[index][1];
            int sell = prices[index] - fee + helper(prices, index + 1, false, fee, dp);
            int wait = helper(prices, index + 1, hold, fee, dp);
            dp[index][1] = max(sell, wait);
            return dp[index][1];
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, 0, false, fee, dp);
    }
};

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution sol;
    cout << "Maximum Profit: " << sol.maxProfit(prices, fee) << endl;
    return 0;
}