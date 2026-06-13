#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
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

        int sum = 0;
        int Min = 1e9;
        for (int i = 1;i <= n;i++) {
            sum += a[i];
            int cnt = sum / i;
            Min = min(Min,cnt);
            a[i] = Min;
        }

        for (int i = 1;i <= n;i++) {
            cout << a[i] << " ";
        }

        cout << "\n";
    }
}