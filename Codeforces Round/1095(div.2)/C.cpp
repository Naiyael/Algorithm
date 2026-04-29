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
        vector<int> a(n);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }

        sort(a.begin(),a.end());

        int l = 0,r = n;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<bool> target(mid,false);
            vector<bool> vis(n,false);

            for (int i = 0;i < n;i++) {
                if (a[i] < mid && !target[a[i]]) {
                    target[a[i]] = true;
                    vis[i] = true;
                }
                
            }

            vector<int> unuse;
            for (int i = 0;i < mid;i++) {
                if (!target[i]) {
                    unuse.push_back(i);
                }
            }

            int p = 0;
            for (int i = 0;i < n && p < unuse.size();i++) {
                if (!vis[i]) {
                    if (a[i] >= 2 * unuse[p] + 1) {
                        p++;
                    }
                }
            }

            bool flag = (p == unuse.size());

            if (flag) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}