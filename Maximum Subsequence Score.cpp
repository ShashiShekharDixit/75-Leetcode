#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long result = 0;
        long long totalSum = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<pair<int, int>> merged;
        
        for (int i = 0; i < nums1.size(); i++) {
            merged.push_back({nums2[i], nums1[i]});
        }
        
        sort(merged.begin(), merged.end(), greater<pair<int, int>>());
        
        for (const auto& [maxOf2, num1Val] : merged) {
            if (heap.size() == k) {
                totalSum -= heap.top();
                heap.pop();
            }
            totalSum += num1Val;
            heap.push(num1Val);
            
            if (heap.size() == k) {
                result = max(result, totalSum * static_cast<long long>(maxOf2));
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 3, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    int k = 2;

    long long result = solution.maxScore(nums1, nums2, k);
    cout << "Maximum Score: " << result << endl;

    return 0;
}
