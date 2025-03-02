#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    RecentCounter counter;
    int n;
    
    cout << "Enter the number of pings: ";
    cin >> n;

    cout << "Enter the ping times:\n";
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cout << "Number of pings in last 3000 ms: " << counter.ping(t) << endl;
    }

    return 0;
}
