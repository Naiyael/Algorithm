#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2010;
int dp[N][N];

int main() {
    int n,k;
    cin >> n >> k;

    for (int i = 1;i <= n;i++) {
        dp[1][i] = 1;
    }

    for (int i = 1;i < k;i++) {
        for (int j = 1;j <= n;j++) {
            for (int next = j;next <= n;next += j) {
                dp[i + 1][next] = (dp[i + 1][next] + dp[i][j]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = (ans + dp[k][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}