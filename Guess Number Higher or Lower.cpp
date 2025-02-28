#include <iostream>

using namespace std;

int guess(int num) {
    int pickedNumber = 6; 
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        long long mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (guess(mid) == 0)
                return mid;
            if (guess(mid) == -1) {
                high = mid - 1;
            }
            if (guess(mid) == 1) {
                low = mid + 1;
            }
            if (low == high)
                return low;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    int n = 10; 
    cout << "Guessed Number: " << sol.guessNumber(n) << endl;
    return 0;
}