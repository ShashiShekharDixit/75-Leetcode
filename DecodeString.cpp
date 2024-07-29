class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return helper(i,s);
    }
    string helper(int &idx,string s){
        int n=0;
        string ans="";
        while(idx<s.size()){
            char c=s[idx];
            if(c>='0' && c<='9') n=n*10 +c-'0';
            else if(c=='['){
                string temp=helper(++idx,s);
                while(n>0){
                    ans+=temp;
                    n--;
                }
            }
            else if(c==']') return ans;
            else ans+=c;
            idx++;
        }
        return ans;
    }
};