#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 676767677;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int ans = 0;
        int index = 0;

        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] >= 2) {
                ans = (ans + a[i]) % MOD;
                index = i;
            }
        }

        bool flag = false;
        for (int i = index + 1;i <= n;i++) {
            if (a[i] == 1) {
                flag = true;
                break;
            }
        }

        if (flag) {
            ans = (ans + 1) % MOD;
        }

        cout << ans << endl;
    }
    return 0;
}