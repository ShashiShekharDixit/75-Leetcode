#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Before moving zeros: ";
    printArray(nums);
    
    solution.moveZeroes(nums);
    
    cout << "After moving zeros: ";
    printArray(nums);
    
    return 0;
}
