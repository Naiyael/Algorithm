#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int dp[N];
int add[N];

signed main() {
    int t,k;
    cin >> t >> k;

    dp[0] = 1;
    for (int i = 1;i < N;i++) {
        if (i < k) {
            dp[i] = 1;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
        }
    }

    add[0] = dp[0];
    for (int i = 1;i < N;i++) {
        add[i] = (add[i - 1] + dp[i]) % MOD;
    }

    while (t--) {
        int l,r;
        cin >> l >> r;
        int ans = (add[r] - add[l - 1] + MOD) % MOD;

        cout << ans << endl;
    }
}