#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int ans = 0;
        int ones = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) k--;
            ones++;
            while (k < 0) {
                if (nums[j] == 0) k++;
                ones--;
                j++;
            }
            ans = max(ans, ones);
        }
        return ans - 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1}; // Example input
    int result = solution.longestSubarray(nums);
    cout << "Longest Subarray Length After Deleting One Element: " << result << endl;
    return 0;
}
