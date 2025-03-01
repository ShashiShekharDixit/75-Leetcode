#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int fl = 1;
                for (int i = 0; i < n; ++i) {
                    if (grid[r][i] != grid[i][c]) {
                        fl = 0;
                        break;
                    }
                }
                ans += fl;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{3, 2, 1}, {2, 3, 2}, {1, 2, 3}};
    cout << "Number of equal row-column pairs: " << sol.equalPairs(grid) << endl;
    return 0;
}
