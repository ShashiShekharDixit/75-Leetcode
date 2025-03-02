#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int largest = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= largest)
                ans[i] = true;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;

    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);

    for (bool val : result1) {
        cout << (val ? "True " : "False ");
    }
    cout << endl;

    for (bool val : result2) {
        cout << (val ? "True " : "False ");
    }
    cout << endl;

    return 0;
}
