class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> rvadj[n];

        for(auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            rvadj[connection[1]].push_back(connection[0]);
        }

        queue<int> q;
        int op = 0;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                int node = q.front();
                q.pop();

                for(auto x : adj[node])
                {
                    if(vis[x] != 1)
                    {
                        vis[x] = 1;
                        op++;
                        q.push(x);
                    }
                }
                for(auto x : rvadj[node])
                {
                    if(vis[x] != 1)
                    {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
        }

        return op;
    }
};