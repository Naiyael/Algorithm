#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int cnt[N];
int dp[N];

signed main() {
    int n;
    cin >> n;
    int Max = 0;
    memset(cnt,0,sizeof cnt);
    memset(dp,0,sizeof dp);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]] += a[i];
        Max = max(Max,a[i]);
    }
    dp[0] = 0;
    dp[1] = cnt[1];

    for (int i = 2;i <= Max;i++) {
        int cnt1 = dp[i - 1];
        int cnt2 = dp[i - 2] + cnt[i];

        dp[i] = max(cnt1,cnt2);
    }

    cout << dp[Max] << endl;
}