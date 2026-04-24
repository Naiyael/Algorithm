#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int pre[N];
int a[N];
int edge[N];

void init(int n) {
    for (int i = 1;i <= n;i++) {
        pre[i] = i;
        a[i] = 1;
        edge[i] = 0;
    }
}

int find(int x) {
    if (pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

void join(int x,int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        pre[fx] = fy;
        a[fy] += a[fx];
        edge[fy] += edge[fx] + 1;
    }
    else {
        edge[fy]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    init(n);
    for (int i = 0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        join(u,v);
    }

    int ans = 0;

    for (int i = 1;i <= n;i++) {
        if (find(i) == i) {
            if (edge[i] == a[i] - 1) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}