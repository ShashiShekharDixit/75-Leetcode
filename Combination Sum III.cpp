#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int sum = 0;
    void dfs(vector<int>& cur, int k, int n, int idx) {
        if (cur.size() == k && sum == n) {
            ans.push_back(cur);
            return;
        } else if (cur.size() == k && sum > n) return;
        for (int i = idx; i <= 9; i++) {
            cur.push_back(i);
            sum += i;
            dfs(cur, k, n, i + 1);
            cur.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(cur, k, n, 1);
        return ans;
    }
};

int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);
    
    cout << "Combinations: " << endl;
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}