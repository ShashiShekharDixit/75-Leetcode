#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++)
            pairs.push_back(m - (lower_bound(potions.begin(), potions.end(), (double)success / spells[i]) - potions.begin()));
        return pairs;
    }
};

int main() {
    Solution solution;

    vector<int> spells1 = {10, 20, 30};
    vector<int> potions1 = {1, 2, 3, 4, 5};
    long long success1 = 20;
    
    vector<int> result1 = solution.successfulPairs(spells1, potions1, success1);
    
    cout << "Successful Pairs: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> spells2 = {5, 1, 3};
    vector<int> potions2 = {1, 2, 3, 4, 5};
    long long success2 = 7;

    vector<int> result2 = solution.successfulPairs(spells2, potions2, success2);
    
    cout << "Successful Pairs: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
