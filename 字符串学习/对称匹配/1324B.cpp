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

        int l = 1;
        int r = 3;
        bool flag = false;
        while (l <= n - 2) {
            if (a[l] == a[r]) {
                flag = true;
                break;
            }
            r++;
            if (r == n + 1) {
                l++;
                r = l + 2;
            }
        }
        if (!flag) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}