#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e18;

struct Edge {
    int to;
    int weight;
};

struct Road {
    int u,v,w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n + 1);
    vector<Road> roads(m);

    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        roads[i] = {u, v, w};
    }

    int l;
    cin >> l;

    vector<int> minDist(n + 1,INF);
    vector<bool> vis(n + 1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    minDist[s] = 0;
    pq.push({0,s});

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

    int ans = 0;

    for (int i = 1;i <= n;i++) {
        if (minDist[i] == l) {
            ans++;
        }
    }

    for (int i = 0;i < m;i++) {
        int u = roads[i].u;
        int v = roads[i].v;
        int w = roads[i].w;

        bool valid_u = false;
        bool valid_v = false;

        int x = l - minDist[u];
        if (x > 0 && x < w) {
            if (minDist[v] + w - x >= l) {
                valid_u = true;
                ans++;
            }
        }

        int y = l - minDist[v];
        if (y > 0 && y < w) {
            if (minDist[u] + w - y >= l) {
                valid_v = true;
                ans++;
            }
        }

        if (valid_u && valid_v && x + y == w) {
            ans--;
        }
    }

    cout << ans << endl;

    return 0;
}