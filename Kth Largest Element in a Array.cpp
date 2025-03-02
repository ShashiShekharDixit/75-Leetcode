#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;

    cout << solution.findKthLargest(nums1, k1) << endl;
    cout << solution.findKthLargest(nums2, k2) << endl;

    return 0;
}
