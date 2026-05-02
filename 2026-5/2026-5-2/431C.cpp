#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,d;
    cin >> n >> k >> d;

    vector<vector<long long>> dp(n + 1,vector<long long>(2,0));

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= k;j++) {
            if (i - j < 0) continue;

            if (j < d) {
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % MOD;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;
            }
            else {
                dp[i][1] = (dp[i][1] + dp[i - j][0] + dp[i - j][1]) % MOD;
            }
        }
    }

    cout << dp[n][1] << endl;

    return 0;
}