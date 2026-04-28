#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e18;

struct Edge {
    int to;
    int weight;
    int id;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<Edge>> edges(n + 1);
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges[u].push_back({v,w,i});
        edges[v].push_back({u,w,i});
    }

    vector<int> minDist(n + 1,INF);
    vector<int> parent(n + 1,-1);
    vector<bool> vis(n + 1,false);
    vector<int> minweight(n + 1,INF);
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

    int u;
    cin >> u;
    minDist[u] = 0;
    minweight[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (auto edge : edges[cur]) {
            int to = edge.to;
            int weight = edge.weight;
            int id = edge.id;

            if (!vis[to] && minDist[cur] + weight < minDist[to]) {
                minDist[to] = minDist[cur] + weight;
                parent[to] = id;
                minweight[to] = weight;
                pq.push({minDist[to],to});
            }
            else if (!vis[to] && minDist[cur] + weight == minDist[to]) {
                if (weight < minweight[to]) {
                    minweight[to] = weight;
                    parent[to] = id;
                }
            }
        }
    }

    int Min = 0;
    for (int i = 1;i <= n;i++) {
        Min += minweight[i];
    }
    cout << Min << endl;

    for (int i = 1;i <= n;i++) {
        if (i != u) {
            cout << parent[i] << " ";
        }
    }
    cout << endl;

    return 0;
}