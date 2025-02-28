#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;
        for(auto i : nums) {
            sum += i;
        }
        for(int i = 0; i < nums.size(); i++){
            sum -= nums[i];
            if(leftSum == sum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivot = sol.pivotIndex(nums);
    cout << "Pivot Index: " << pivot << endl;
    return 0;
}