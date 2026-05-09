#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }

    vector<string> a(n + 1);
    vector<string> ra(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        ra[i] = a[i];
        reverse(ra[i].begin(),ra[i].end());
    }

    vector<vector<int>> dp(n + 1,vector<int>(2,1e18));
    dp[1][0] = 0;
    dp[1][1] = c[1];

    for (int i = 2;i <= n;i++) {
        if (a[i - 1] <= a[i]) {
            dp[i][0] = min(dp[i][0],dp[i - 1][0]);
        }
        if (ra[i - 1] <= a[i]) {
            dp[i][0] = min(dp[i - 1][1],dp[i][0]);
        }
        if (a[i - 1] <= ra[i]) {
            dp[i][1] = min(dp[i][1],dp[i - 1][0] + c[i]);
        }
        if (ra[i - 1] <= ra[i]) {
            dp[i][1] = min(dp[i][1],dp[i - 1][1] + c[i]);
        }
    }

    int ans = min(dp[n][0],dp[n][1]);

    if (ans == 1e18) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}