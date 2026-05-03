#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    if (n >= m) {
        cout << "YES" << endl;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    vector<bool> dp(m,false);

    for (int i = 0;i < n;i++) {
        int val = a[i] % m;
        vector<bool> ndp = dp;
        ndp[val] = true;
        for (int j = 0;j < m;j++) {
            if (dp[j]) {
                int need = (j + val) % m;
                ndp[need] = true;
            }
        }

        dp = ndp;

        if (dp[0]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}