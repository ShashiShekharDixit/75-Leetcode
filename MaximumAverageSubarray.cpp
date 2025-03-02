#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = numeric_limits<double>::lowest();
        for (int i = 0; i < k; i++)
            currSum += nums[i];
        maxSum = currSum;
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }
        return maxSum / k;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    Solution solution;
    double result = solution.findMaxAverage(nums, k);
    
    cout << "Maximum average subarray of length " << k << " is: " << result << endl;

    return 0;
}
