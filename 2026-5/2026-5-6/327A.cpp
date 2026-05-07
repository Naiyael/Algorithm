#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> gain(n);
    int cnt = 0;

    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cnt++;
            gain[i] = -1;
        }
        else {
            gain[i] = 1;
        }
    }

    vector<int> dp(n,0);
    dp[0] = gain[0];
    int Max = dp[0];

    for (int i = 1;i < n;i++) {
        dp[i] = max(gain[i],dp[i-1] + gain[i]);
        Max = max(Max,dp[i]);
    }

    cout << cnt + Max << endl;

    return 0;
}