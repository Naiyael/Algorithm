#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin  >> t;

    while (t--) {
        string a,b;
        cin >> a >> b;

        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));

        int Max = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    Max = max(Max,dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        int ans = (n - Max) + (m - Max);
        cout << ans << endl;
    }
    return 0;
}