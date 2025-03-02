#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); 
        vector<vector<string>> result;
        string currentPrefix = "";
        
        for (auto &c : searchWord) {
            currentPrefix += c; 
            vector<string> suggestions;
            auto it = lower_bound(products.begin(), products.end(), currentPrefix);
            int i = 0;
            while (i < 3 && it != products.end() && it->substr(0, currentPrefix.size()) == currentPrefix) {
                suggestions.push_back(*it);
                ++i;
                ++it;
            }
            result.push_back(suggestions);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> result = sol.suggestedProducts(products, searchWord);

    for (auto &suggestions : result) {
        for (auto &word : suggestions) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
