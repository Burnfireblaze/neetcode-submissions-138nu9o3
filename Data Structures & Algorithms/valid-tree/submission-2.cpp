class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        if (edges.size() != n-1)
        return false;
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, adj, visited);
        

        for(auto check : visited){
            if(check == false)
            return false;
        }

        return true;
    }
};
