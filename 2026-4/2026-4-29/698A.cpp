#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 1e9;
int dp[N][3];

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for (int i = 0;i <= n;i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = INF;
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1;i <= n;i++) {
        dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;

        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }

        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl;
    return 0;
}