#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); 
        vector<vector<string>>result;
        string currentPrefix = "";
        for(auto&c : searchWord){
            currentPrefix+=c; 
            vector<string> suggestions;
            auto it = lower_bound(products.begin(), products.end(), currentPrefix);
            int i = 0;
        while(i < 3 && it != products.end() && it->substr(0, currentPrefix.size()) == currentPrefix){
            suggestions.push_back(*it);
            ++i;
            ++it;
        }
            result.push_back(suggestions);
        }
        
        return result;
    }
};