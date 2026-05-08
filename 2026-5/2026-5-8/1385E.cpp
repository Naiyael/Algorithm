#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1, 0);
        vector<pair<int, int>> edges;

        for (int i = 0;i < m;i++) {
            int type,u,v;
            cin >> type >> u >> v;
            edges.push_back({u,v});

            if (type == 1) {
                adj[u].push_back(v);
                in[v]++;
            }
        }

        queue<int> q;
        for (int i = 1;i <= n;i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> pos(n + 1,0);
        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            pos[u] = ++count;

            for (int v : adj[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (count < n) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (int i = 0;i < m;i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            if (pos[u] < pos[v]) {
                cout << u << " " << v << endl;
            } else {
                cout << v << " " << u << endl;
            }
        }
    }

    return 0;
}