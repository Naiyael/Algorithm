#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n + 1,INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        for (int j = n; j >= 0; j--) {
            if (dp[j] != INF) {
                int nj = min(n,j + t + 1);
                dp[nj] = min(dp[nj],dp[j] + c);
            }
        }
    }
    cout << dp[n] << endl;
}