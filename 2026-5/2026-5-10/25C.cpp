#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 310;
int a[N][N];

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }

    int k;
    cin >> k;

    while (k--) {
        int u,v,w;
        cin >> u >> v >> w;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                a[i][j] = min({a[i][j],a[i][u] + w + a[v][j],a[i][v] + w + a[u][j]});
            }
        }

        int ans = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= i;j++) {
                ans += a[i][j];
            }
        }
        cout << ans << " ";
    }
}