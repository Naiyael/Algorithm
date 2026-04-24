#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
bool vis[N];
int in[N];
int n, m;

void dfs(int x, bool &flag) {
    vis[x] = true;

    if (in[x] != 2) {
        flag = false;
    }

    for (int i : g[x]) {
        if (!vis[i]) {
            dfs(i, flag);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        in[x]++;
        in[y]++;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bool flag = true;
            dfs(i, flag);
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}