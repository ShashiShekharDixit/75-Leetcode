#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = 0, maxVows = 0, n = s.size(), cnt = 0;
        while (r < n) {
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                cnt++;
            }
            if ((r - l + 1) > k) {
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                    cnt--;
                }
                l++;
            }
            maxVows = max(maxVows, cnt);
            r++;
        }
        return maxVows;
    }
};

int main() {
    string s = "abciiidef";
    int k = 3;

    Solution solution;
    int result = solution.maxVowels(s, k);

    cout << "Maximum number of vowels in any substring of length " << k << " is: " << result << endl;

    return 0;
}
