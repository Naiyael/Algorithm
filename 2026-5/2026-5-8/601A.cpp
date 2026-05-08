#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1,vector<int>(n + 1,0));

    for (int i = 0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    int flag = (a[1][n] == 1) ? 0 : 1;

    queue<int> q;
    vector<int> vis(n + 1,0);
    vector<int> step(n + 1,0);

    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n) {
            cout << step[n] << endl;
            return 0;
        }

        for (int next = 1;next <= n;next++) {
            if (curr == next) continue;

            if (a[curr][next] == flag && !vis[next]) {
                vis[next] = 1;
                step[next] = step[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}