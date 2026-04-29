#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    int ans = 0;
    int l = 1;
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        sum += a[i];
        while (sum > t) {
            sum -= a[l];
            l++;
        }
        ans = max(ans,i - l + 1);
    }
    cout << ans << endl;
}
