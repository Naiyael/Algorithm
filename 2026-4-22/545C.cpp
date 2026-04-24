#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int x[N];
int h[N];

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x[i] >> h[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 2;
    for (int i = 2;i < n;i++) {
        if (x[i] - h[i] > x[i - 1]) {
            ans++;
        }
        else if (x[i] + h[i] < x[i + 1]) {
            ans++;
            x[i] = x[i] + h[i];
        }
    }
    cout << ans << endl;
}