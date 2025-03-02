#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        bool vowels[128];
        memset(vowels, false, sizeof(vowels));
        for (char c : "aeiouAEIOU") {
            vowels[c] = true;
        }
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !vowels[s[i]]) {
                ++i;
            }
            while (i < j && !vowels[s[j]]) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "hello";
    
    string result = sol.reverseVowels(s);
    
    cout << "Reversed vowels string: " << result << endl; 

    return 0;
}
