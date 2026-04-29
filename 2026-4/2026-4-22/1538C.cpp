#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n + 1);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());

        int ans = 0;

        for (int i = 1;i < n;i++) {

            int min_val = l - a[i];
            int max_val = r - a[i];

            auto left = lower_bound(a.begin() + i + 1, a.end(), min_val);
            auto right = upper_bound(a.begin() + i + 1, a.end(), max_val);

            ans += distance(left, right);
        }

        cout << ans << endl;
    }
    return 0;
}