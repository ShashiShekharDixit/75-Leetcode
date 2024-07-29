class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        int n = s.size();
        int i = 0;
        while(i < n) {
            if(s[i] == '*'){
                st.pop();
            }
            else {
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};