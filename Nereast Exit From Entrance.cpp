class Solution {
    bool isValid(int n, int m, int row, int col){
        if(row >= 0 and row < n and col >= 0 and col < m){
            return true;
        }
        return false;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>>q;
        q.push(make_pair(entrance[0], entrance[1]));
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        vector<vector<int>>d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int>p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if((x == 0 or y == 0 or x == n - 1 or y == m - 1)){
                    if((x != entrance[0] or y != entrance[1]))
                    return steps;
                }
                for(int k = 0; k < 4; k++){a
                    int nx = x + d[k][0];
                    int ny = y + d[k][1];
                    if(isValid(n, m, nx, ny) == true and maze[nx][ny] != '+'){
                        maze[nx][ny] = '+';
                        q.push(make_pair(nx,ny));
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};