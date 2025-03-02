#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> v;
        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }
            v.push_back(cnt);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << (solution.uniqueOccurrences(arr1) ? "true" : "false") << endl;

    vector<int> arr2 = {1, 2};
    cout << (solution.uniqueOccurrences(arr2) ? "true" : "false") << endl;

    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << (solution.uniqueOccurrences(arr3) ? "true" : "false") << endl;

    return 0;
}
