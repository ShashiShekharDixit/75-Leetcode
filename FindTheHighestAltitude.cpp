#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int height = 0, altitude = 0;
        for(int i = 0; i < n; i++){
            altitude += gain[i];
            height = max(height, altitude);
        }
        return height;
    }
};

int main() {
    Solution sol;
    vector<int> gain = {-5, 1, 5, 0, -7};
    cout << "Highest Altitude: " << sol.largestAltitude(gain) << endl;
    return 0;
}