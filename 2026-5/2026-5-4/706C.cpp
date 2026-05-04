#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int INF = 1e18;

signed main() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    vector<string> s(n + 1);
    vector<string> rs(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(),rs[i].end());
    }
    vector<vector<int>> dp(n + 1,vector<int>(2,INF));
    dp[1][0] = 0;
    dp[1][1] = c[1];

    for (int i = 2;i <= n;i++) {
        if (s[i - 1] <= s[i]) {
            dp[i][0] = min(dp[i][0],dp[i - 1][0]);
        }
        if (rs[i - 1] <= s[i]) {
            dp[i][0] = min(dp[i - 1][1],dp[i][0]);
        }
        if (s[i - 1] <= rs[i]) {
            dp[i][1] = min(dp[i][1],dp[i - 1][0] + c[i]);
        }
        if (rs[i - 1] <= rs[i]) {
            dp[i][1] = min(dp[i][1],dp[i - 1][1] + c[i]);
        }
    }

    int ans = min(dp[n][0],dp[n][1]);

    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}