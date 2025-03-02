#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(string digits, string output, int i, vector<string>& ans, string mapping[]) {
        if (i >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int num = digits[i] - '0';
        string value = mapping[num];
        for (int j = 0; j < value.length(); j++) {
            output.push_back(value[j]);
            solve(digits, output, i + 1, ans, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        int i = 0;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, i, ans, mapping);
        return ans;
    }
};

int main() {
    Solution solution;
    
    string digits1 = "23";
    string digits2 = "5";

    vector<string> result1 = solution.letterCombinations(digits1);
    vector<string> result2 = solution.letterCombinations(digits2);

    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;

    for (const string& s : result2) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
