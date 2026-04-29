#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
const int INF = 1e18;

struct Node {
    int to, w;
};

vector<Node> g[N];
int dist[N];
bool vis[N];
int pre[N];

void dijkstra(int s) {
    for (int i = 0; i < N; i++) dist[i] = INF;
    for (int i = 0; i < N; i++) vis[i] = false;
    for (int i = 0; i < N; i++) pre[i] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto e : g[u]) {
            int v = e.to, w = e.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void print_path(int v) {
    if (v == -1) return;
    print_path(pre[v]);
    cout << v << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(1);

    if (dist[n] == INF) {
        cout << -1 << endl;
    }
    else {
        print_path(n);
        cout << endl;
    }

    return 0;
}