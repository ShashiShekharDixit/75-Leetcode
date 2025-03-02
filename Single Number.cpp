#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        for(int i = 0; i < nums.size(); i++) {
            singleNumber ^= nums[i];
        }
        return singleNumber;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; 
    Solution solution;
    int result = solution.singleNumber(nums);
    cout << "The single number is: " << result << endl;
    return 0;
}
