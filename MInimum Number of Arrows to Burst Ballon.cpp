#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lastpoint = points[0][1];
        int ans = 1;
        for(auto p : points) {
            if(p[0] > lastpoint) {
                ans++;
                lastpoint = p[1];
            }
            lastpoint = min(p[1], lastpoint);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points1 = {{10,16}, {2,8}, {1,6}, {7,12}};
    vector<vector<int>> points2 = {{1,2}, {3,4}, {5,6}, {7,8}};
    vector<vector<int>> points3 = {{1,2}, {2,3}, {3,4}, {4,5}};

    cout << solution.findMinArrowShots(points1) << endl;
    cout << solution.findMinArrowShots(points2) << endl;
    cout << solution.findMinArrowShots(points3) << endl;

    return 0;
}
