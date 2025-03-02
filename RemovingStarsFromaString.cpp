#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "Shas*h*i**"; 
    string result = sol.removeStars(s);
    cout << "Output: " << result << endl; 
    return 0;
}
