#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
int vis[N];
int ans = 0;
int n,m;


void dfs(int u,int root,int cnt) {
    if (vis[u] == 1) {
        cnt++;
    }
    else {
        cnt = 0;
    }

    if (cnt > m) {
        return;
    }

    bool flag = true;
    for (int v : adj[u]) {
        if (v != root) {
            flag = false;
            dfs(v,u,cnt);
        }
    }

    if (flag) {
        ans++;
    }
}

int main() {
    cin >> n >> m;
    memset(vis,false,sizeof vis);
    for (int i = 1;i <= n;i++) {
        cin >> vis[i];
    }

    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}