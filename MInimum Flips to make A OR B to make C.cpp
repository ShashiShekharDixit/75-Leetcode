#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int minFlips = 0;
        while(a != 0 || b != 0 || c != 0) {
            int bit1 = a & 1;
            int bit2 = b & 1;
            int bit3 = c & 1;
            if(bit3 != (bit2 | bit1)) {
                if(bit3 == 1) {
                    minFlips += 1;
                } else {
                    minFlips += (bit2 + bit1);
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return minFlips;
    }
};

int main() {
    Solution solution;
    cout << solution.minFlips(2, 6, 5) << endl;
    cout << solution.minFlips(4, 2, 7) << endl;
    cout << solution.minFlips(1, 2, 3) << endl;
    return 0;
}
