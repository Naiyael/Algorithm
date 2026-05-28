#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }

        int k = 0;
        int Max = a[1];

        for (int i = 2;i <= n;i++) {
            Max = max(Max,a[i]);
            if (Max - a[i] > 0) {
                k = max(k,Max - a[i]);
            }
        }

        int cur = a[1];
        bool flag = true;

        for (int i = 2;i <= n;i++) {
            int v1 = a[i];
            int v2 = a[i] + k;
            if (v1 >= cur) {
                cur = v1;
            }
            else if (v2 >= cur) {
                cur = v2;
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}