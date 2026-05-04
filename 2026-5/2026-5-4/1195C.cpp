#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int dp[N][3];

signed main() {
    int n;
    cin >> n;
    vector<int> h1(n + 1);
    vector<int> h2(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> h1[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> h2[i];
    }

    for (int i = 1;i <= n;i++) {
        dp[i][0] = max({dp[i - 1][0],dp[i - 1][1],dp[i - 1][2]});

        dp[i][1] = max(dp[i - 1][0],dp[i - 1][2]) + h1[i];

        dp[i][2] = max(dp[i - 1][0],dp[i - 1][1]) + h2[i];
    }

    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max({dp[i][0],dp[i][1],dp[i][2]});
    }
    cout << ans << endl;
}