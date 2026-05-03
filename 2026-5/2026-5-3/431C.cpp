#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1010;
int dp[N][2];

signed main() {
    int n,k,d;
    cin >> n >> k >> d;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= k;j++) {
            if (i - j < 0) {
                continue;
            }

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
}