#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for(int i = 0; i < chars.size();) {
            const char letter = chars[i];
            int count = 0;
            while(i < chars.size() && chars[i] == letter) {
                ++count;
                ++i;
            }
            chars[ans++] = letter;
            if(count > 1) {
                for(const char c : to_string(count)){
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength1 = solution.compress(chars1);
    cout << "Compressed Length: " << newLength1 << "\nCompressed String: ";
    for(int i = 0; i < newLength1; i++) {
        cout << chars1[i];
    }
    cout << endl;

    vector<char> chars2 = {'a'};
    int newLength2 = solution.compress(chars2);
    cout << "Compressed Length: " << newLength2 << "\nCompressed String: ";
    for(int i = 0; i < newLength2; i++) {
        cout << chars2[i];
    }
    cout << endl;

    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int newLength3 = solution.compress(chars3);
    cout << "Compressed Length: " << newLength3 << "\nCompressed String: ";
    for(int i = 0; i < newLength3; i++) {
        cout << chars3[i];
    }
    cout << endl;

    return 0;
}
