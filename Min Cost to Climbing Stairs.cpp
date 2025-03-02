#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0, prev1 = 0;
        for(int i = 2; i <= cost.size(); i++){
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution solution;
    vector<int> cost = {10, 15, 20};
    cout << solution.minCostClimbingStairs(cost) << endl;
    
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost2) << endl;

    return 0;
}
