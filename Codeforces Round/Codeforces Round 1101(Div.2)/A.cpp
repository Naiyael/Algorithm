#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1,a.end());

        int ans = 0;
        int l = 1;
        int r = n;
        while (l <= r) {
            if (a[l] != a[r]) {
                ans++;
            }
            l++;
            r--;
        }
        cout << ans << "\n";
    }
    return 0;
}