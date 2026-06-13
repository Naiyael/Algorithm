#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,x,s;
        cin >> n >> x >> s;
        string u;
        cin >> u;

        vector<int> dp(x + 1,-1);
        dp[0] = 0;

        for (char c : u) {
            vector<int> ndp = dp;

            for (int j = 0;j <= x;j++) {
                if (dp[j] == -1) {
                    continue;
                }

                if ((c == 'I' || c == 'A') && j < x) {
                    ndp[j + 1] = max(ndp[j + 1],dp[j] + 1);
                }

                if ((c == 'E' || c == 'A') && j * s > dp[j]) {
                    ndp[j] = max(ndp[j],dp[j] + 1);
                }
            }

            dp = ndp;
        }

        int ans = 0;
        for (int j = 0;j <= x;j++) {
            ans = max(ans,dp[j]);
        }

        cout << ans << "\n";
    }
    return 0;
}