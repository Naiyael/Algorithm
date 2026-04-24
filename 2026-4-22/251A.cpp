#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,d;
    cin >> n >> d;

    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int l = 1;l <= n - 2;l++) {
        int x = a[l] + d;
        int i = upper_bound(a.begin() + 1,a.end(),x) - a.begin() - 1;
        int y = i - l;
        if (y >= 2) {
            ans += y * (y - 1) / 2;
        }
    }
    cout << ans << endl;
}