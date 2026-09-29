#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG = LLONG_MIN;



ll findMaxPath(int n, const vector<vector<int>>& edges, int src, int dst) {
        vector<ll> dist(n, NEG);
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++){
                bool changed = false;
                for (const vector<int> &e : edges){
                        if (dist[e[0]] == NEG) continue;
                        ll cand = dist[e[0]] + e[2];
                        if (cand > dist[e[1]]) {
                                dist[e[1]] = cand;
                                changed = true;
                        }
                }
                if (!changed) break;
        }

        return dist[dst] == NEG ? -1 : dist[dst];
}

int main(){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++){
                cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
                edges[i][0]--;
                edges[i][1]--;
        }

        cout << findMaxPath(n, edges, 0, n - 1) << endl;
}
