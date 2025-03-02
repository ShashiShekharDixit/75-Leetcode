#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_small = INT_MAX;
        int second_small = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first_small)
                first_small = nums[i];
            else if (nums[i] <= second_small)
                second_small = nums[i];
            else 
                return true;
        } 
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};

    cout << (solution.increasingTriplet(nums1) ? "True\n" : "False\n");
    cout << (solution.increasingTriplet(nums2) ? "True\n" : "False\n");
    cout << (solution.increasingTriplet(nums3) ? "True\n" : "False\n");

    return 0;
}
