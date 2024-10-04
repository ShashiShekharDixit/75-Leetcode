class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        long long mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(guess(mid) == 0)
            return mid;
            if(guess(mid) == -1){
                high = mid - 1;
            }
            if(guess(mid) == 1){
                low = mid + 1;
            }
            if(low == high)
            return low;
        }
        return 0;
    }
};