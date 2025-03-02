#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0, right = 0, i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i == n) break;
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }
};

int main() {
    Solution sol;
    string s = "  hello world  ";
    string result = sol.reverseWords(s);
    cout << "Reversed words string: \"" << result << "\"" << endl;
    return 0;
}
