#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;
        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }
        return sp == s.length();
    }
};

int main() {
    Solution solution;
    
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";
    
    cout << (solution.isSubsequence(s1, t1) ? "True\n" : "False\n");
    cout << (solution.isSubsequence(s2, t2) ? "True\n" : "False\n");

    return 0;
}
