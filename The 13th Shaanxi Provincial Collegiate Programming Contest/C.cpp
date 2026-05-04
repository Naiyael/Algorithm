#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        int x = b;
        while (gcd(a,x) != 1) {
            x /= gcd(a,x);
            if (x == 1) {
                break;
            }
        }
        if (x == 1) {
            cout << -1 << endl;
        }
        else {
            cout << x << endl;
        }
    }
}