#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int cnt = 0;
        int i = 0;
        int j = costs.size() - 1;
        while(cnt < k){
            while(pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
            while(pq2.size() < candidates && j >= i) pq2.push(costs[j--]);
            int cost1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int cost2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(cost1 <= cost2){
                ans += cost1;
                pq1.pop();
            } else {
                ans += cost2;
                pq2.pop();
            }
            cnt++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> costs1 = {10, 20, 30, 40, 50};
    int k1 = 3;
    int candidates1 = 2;

    long long result1 = solution.totalCost(costs1, k1, candidates1);
    cout << "Total Cost (Test Case 1): " << result1 << endl;

    vector<int> costs2 = {1, 2, 3, 4, 5, 6};
    int k2 = 4;
    int candidates2 = 2;

    long long result2 = solution.totalCost(costs2, k2, candidates2);
    cout << "Total Cost (Test Case 2): " << result2 << endl;

    return 0;
}
