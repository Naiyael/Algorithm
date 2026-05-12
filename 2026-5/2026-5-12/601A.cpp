#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1,vector<int>(n + 1,0));
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    int cnt = 1;
    if (a[1][n] == 1) {
        cnt = 0;
    }

    queue<int> q;
    vector<bool> vis(n + 1,false);
    vector<int> step(n + 1,0);

    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n) {
            cout << step[n] << endl;
            return 0;
        }

        for (int i = 1;i <= n;i++) {
            if (cur == i) continue;

            if (a[cur][i] == cnt && !vis[i]) {
                vis[i] = true;
                step[i] = step[cur] + 1;
                q.push(i);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}