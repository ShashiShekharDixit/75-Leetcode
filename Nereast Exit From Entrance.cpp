#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    bool isValid(int n, int m, int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && !(x == entrance[0] && y == entrance[1])) {
                    return steps;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k][0];
                    int ny = y + d[k][1];
                    if (isValid(n, m, nx, ny) && maze[nx][ny] != '+') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };
    vector<int> entrance = {1, 2};

    int result = solution.nearestExit(maze, entrance);
    cout << "Nearest exit steps: " << result << endl;

    return 0;
}
