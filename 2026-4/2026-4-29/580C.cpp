#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
vector<int> adj[N];
int n,m;
int ans = 0;

void dfs(int u,int root,int cnt) {
    if (a[u] == 1) {
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
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}