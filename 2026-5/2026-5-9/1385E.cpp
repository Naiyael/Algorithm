#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> a;
        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1,0);
        for (int i = 1;i <= m;i++) {
            int ti,xi,yi;
            cin >> ti >> xi >> yi;
            a.push_back({xi,yi});
            if(ti == 1) {
                adj[xi].push_back(yi);
                in[yi]++;
            }
        }

        queue<int> q;
        for (int i = 1;i <= n;i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> pos(n + 1,0);
        int cnt = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            pos[u] = ++cnt;

            for (int v : adj[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (cnt < n) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (int i = 0;i < m;i++) {
            int u = a[i].first;
            int v = a[i].second;

            if (pos[u] < pos[v]) {
                cout << u << " " << v << endl;
            }
            else {
                cout << v << " " << u << endl;
            }
        }
    }
    return 0;
}