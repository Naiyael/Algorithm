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
        vector<int> a(n);
        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }

        map<int,int> cnt1;
        map<int,int> cnt2;

        int x = a[0];
        set<int> s;
        int c = 0;

        while (s.find(x) == s.end()) {
            cnt1[x]++;
            cnt2[x] += c;
            s.insert(x);

            if (x & 1) {
                x += 1;
            }
            else {
                x >>= 1;
            }
            c++;
        }
        for (int i = 1;i < n;i++) {
            x = a[i];
            s.clear();
            c = 0;

            while (s.find(x) == s.end()) {
                if (cnt1.count(x)) {
                    cnt1[x]++;
                    cnt2[x] += c;
                }
                s.insert(x);

                if (x & 1) {
                    x += 1;
                }
                else {
                    x >>= 1;
                }
                c++;
            }
        }
        int ans = 1e18;
        for (auto const& [k,v] : cnt1) {
            if (v == n) {
                ans = min(ans,cnt2[k]);
            }
        }
        cout << ans << endl;
    }
}
