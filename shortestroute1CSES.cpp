#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll>dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        ll d = pq.top().first;
        int city = pq.top().second;
        pq.pop();
        if (d != dist[city]) continue;
        for (int i = 0; i < adj[city].size(); i++){
            int c = adj[city][i].first;
            ll dis = adj[city][i].second;
            if (dis + d < dist[c]){
                dist[c] = dis + d;
                pq.push({dist[c], c});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dist[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}


// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, ll>>> adj(n + 1);
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         ll c;
//         cin >> a >> b >> c;
//         adj[a].push_back({b, c});
//     }

//     vector<ll> dist(n + 1, INF);
//     dist[1] = 0;
//     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//     pq.push({0, 1});

//     while (!pq.empty()) {
//         auto [d, u] = pq.top();
//         pq.pop();
//         if (d != dist[u]) continue;
//         for (auto [v, w] : adj[u]) {
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         cout << dist[i] << (i == n ? '\n' : ' ');
//     }
//     return 0;
// }