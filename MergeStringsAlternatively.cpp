#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                result += word1[i];
            }
            if (i < word2.length()) {
                result += word2[i];
            }
            i++;
        }
        return result;
    }
};

int main() {
    string word1 = "abc";
    string word2 = "pqrxyz";

    Solution solution;
    string mergedString = solution.mergeAlternately(word1, word2);

    cout << "Merged String: " << mergedString << endl;

    return 0;
}
