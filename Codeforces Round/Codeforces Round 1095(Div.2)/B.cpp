#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1;i < n;i++) {
            int Max = max(a[i],a[i + 1]);
            int Min = min(a[i],a[i + 1]);
            int g = gcd(a[i],a[i + 1]);
            int cnt = Max - Min;
            if (cnt == g) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}