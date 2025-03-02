#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> rvadj[n];

        for (auto connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            rvadj[connection[1]].push_back(connection[0]);
        }

        queue<int> q;
        int op = 0;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                int node = q.front();
                q.pop();

                for (auto x : adj[node]) {
                    if (vis[x] != 1) {
                        vis[x] = 1;
                        op++;
                        q.push(x);
                    }
                }
                for (auto x : rvadj[node]) {
                    if (vis[x] != 1) {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
        }

        return op;
    }
};

int main() {
    Solution sol;
    int n = 6; 
    vector<vector<int>> connections = {{0,1}, {1,3}, {2,3}, {4,0}, {4,5}}; 

    int result = sol.minReorder(n, connections);

    cout << "Minimum roads to reorder: " << result << endl; 

    return 0;
}
