#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(int k,int n,int m,int x,int y) {
    if (k == 0) {
        if (m > 0 && x > y) {
            return x + n * y;
        }
        else {
            return (n + m) * y;
        }
    }
    else {
        if (m > 0 && x > (k + 1) * y) {
            return x + (n - k) * y;
        }
        else {
            return x + (n - k + m) * y;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m,x,y;
        cin >> n >> m >> x >> y;

        int ans = 0;

        vector<int> a = {0,1,n};

        if (y > 0) {
            a.push_back(x / y - 1);
            a.push_back(x / y);
            a.push_back(x / y + 1);
        }

        for (int k : a) {
            if (k >= 0 && k <= n) {
                ans = max(ans, calc(k,n,m,x,y));
            }
        }

        cout << ans << endl;
    }
    return 0;
}