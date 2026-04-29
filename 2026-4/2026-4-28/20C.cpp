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

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int> minDist(n + 1,INF);
    vector<int> parent(n + 1,-1);
    vector<bool> vis(n + 1,false);

    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

    minDist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        if (cur == n) break;

        for (auto edge : graph[cur]) {
            int to = edge.to;
            int weight = edge.weight;

            if (!vis[to] && minDist[cur] + weight < minDist[to]) {
                minDist[to] = minDist[cur] + weight;
                parent[to] = cur;
                pq.push({minDist[to],to});
            }
        }
    }

    if (minDist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    int curr = n;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(),path.end());

    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}