#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size());
        stack<int> stack;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return results;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    cout << "Daily Temperatures Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}