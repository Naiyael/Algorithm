#include <bits/stdc++.h>
using namespace std;
#define int long long

int quick(int a,int b) {
    int result = 1;
    while (b) {
        if (b & 1) result *= a;
        b >>= 1;
        a *= a;
    }
    return result;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        int n = (int)s.size();
        vector<int> a(n);
        for (int i = 0;i < n;i++) {
            int cnt = s[i] - '0';
            if (cnt > x) {
                a[i] = cnt - 1;
            }
            else {
                a[i] = cnt;
            }
        }
        int ans = 0;
        reverse(a.begin(),a.end());
        for (int i = 0;i < n;i++) {
            ans += a[i] * quick(9,i);
        }
        cout << ans + 1 << endl;
    }
}