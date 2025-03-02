#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& piles, int h, int mid) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            if (piles[i] % mid != 0) {
                ans++;
            }
        }
        return ans <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    
    cout << solution.minEatingSpeed(piles1, h1) << endl;
    cout << solution.minEatingSpeed(piles2, h2) << endl;

    return 0;
}
