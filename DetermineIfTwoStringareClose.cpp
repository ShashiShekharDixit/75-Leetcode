#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for (int i = 0; i < word1.size(); i++) {
            c1[word1[i] - 'a']++;
            c2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (c2[i] == 0 && c1[i] != 0) return false;
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "bca";
    cout << "Are the words close? " << (sol.closeStrings(word1, word2) ? "Yes" : "No") << endl;
    return 0;
}