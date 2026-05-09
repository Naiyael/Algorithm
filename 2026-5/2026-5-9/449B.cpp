#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct Edge {
    int to;
    int weight;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<pair<int, int>> trains(k + 1);
    for (int i = 1;i <= k;i++) {
        int si, yi;
        cin >> si >> yi;
        trains[i] = {si, yi};
        graph[1].push_back({si,yi});
        graph[si].push_back({1,yi});
    }

    vector<int> dist(n + 1,INF);
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> indeg(n + 1,0);
    for (int u = 1;u <= n;u++) {
        for (auto edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w == dist[v]) {
                indeg[v]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1;i <= k;i++) {
        int v = trains[i].first;
        int w = trains[i].second;

        if (w > dist[v]) {
            ans++;
        }
        else if (w == dist[v]) {
            if (indeg[v] > 1) {
                ans++;
                indeg[v]--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}