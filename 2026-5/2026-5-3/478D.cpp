#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    int h = 1;
    while (h * (h + 1) / 2 <= n + m) {
        h++;
    }
    h--;

    if (h == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n + 1,0);
    dp[0] = 1;

    for (int i = 1;i <= h;i++) {
        for (int j = n;j >= i;j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    int ans = 0;
    int need = h * (h + 1) / 2;

    for (int i = 0;i <= n;i++) {
        int p = need - i;
        if (p >= 0 && p <= m) {
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans << endl;
}