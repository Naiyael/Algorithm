#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int a[N];
int add[N];
int dp[N][N];

signed main() {
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add[i] = add[i - 1] + a[i];
    }

    for (int i = 1;i <= k;i++) {
        for (int j = i * m;j <= n;j++) {
            int cnt1 = dp[i][j - 1];
            int cnt2 = dp[i - 1][j - m] + (add[j] - add[j - m]);

            dp[i][j] = max(cnt1,cnt2);
        }
    }

    cout << dp[k][n] << endl;
}