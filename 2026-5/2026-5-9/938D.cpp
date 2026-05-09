#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e18;

struct Edge {
    int to;
    int weight;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,2 * w});
        graph[v].push_back({u,2 * w});
    }
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    vector<int> minDist(n + 1,INF);
    vector<bool> vis(n + 1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for (int i = 1;i <= n;i++) {
        minDist[i] = a[i];
        pq.push({minDist[i],i});
    }

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (auto edge : graph[cur]) {
            int to = edge.to;
            int weight = edge.weight;

            if (!vis[to] && minDist[cur] + weight < minDist[to]) {
                minDist[to] = minDist[cur] + weight;
                pq.push({minDist[to],to});
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        cout << minDist[i] << " ";
    }
}