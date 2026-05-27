#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> l;
        set<char> r;

        vector<int> ll(n + 1);
        for (int i = 0;i < n;i++) {
            l.insert(s[i]);
            ll[i] = (int)l.size();
        }

        vector<int> rr(n + 1);
        for (int i = n - 1;i > 0;i--) {
            r.insert(s[i]);
            rr[i] = (int)r.size();
        }

        int ans = 0;
        for (int i = 0;i < n;i++) {
            ans = max(ans,rr[i + 1] + ll[i]);
        }

        cout << ans << endl;
    }
    return 0;
}