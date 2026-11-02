class Solution {
public:
    vector<int> count;
    vector<int>dist;
    vector<vector<int>> adj;
    void reroot(int u, int p, int& n) {
        for (int v : adj[u]) if (v != p) {
            dist[v] = dist[u] - count[v] + (n - count[v]);
            reroot(v, u, n);
        }
    }
    void dfs(int u, int p) {
        for (int v : adj[u]) if (v != p) {
            dfs(v, u);
            count[u] += count[v];
            dist[u] += dist[v] + count[v];
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        count.resize(n, 1);
        dist.resize(n, 0);

        dfs(0, -1);

        reroot(0, -1, n);
        return dist;
    }
};
