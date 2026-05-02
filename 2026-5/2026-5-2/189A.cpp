#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
int dp[N];
int main() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int len[3] = {a,b,c};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = len[i];j <= n;j++) {
            if (dp[j - len[i]] != -1) {
                dp[j] = max(dp[j - len[i]] + 1,dp[j]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}