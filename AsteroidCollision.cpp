#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    
    for (int asteroid : asteroids) {
        bool destroyed = false;
        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            if (st.top() < -asteroid) {
                st.pop();
                continue;
            } else if (st.top() == -asteroid) {
                st.pop();
            }
            destroyed = true;
            break;
        }
        if (!destroyed) {
            st.push(asteroid);
        }
    }
    
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    
    cout << "Remaining asteroids: ";
    for (int ast : result) {
        cout << ast << " ";
    }
    cout << endl;
    
    return 0;
}
