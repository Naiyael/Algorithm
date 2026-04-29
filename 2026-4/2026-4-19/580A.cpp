#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0;i < n;i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1;i < n;i++) {
        if (a[i] >= a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 1;i < n;i++) {
        ans = max(ans,dp[i]);
    }

    cout << ans << endl;
    return 0;
}