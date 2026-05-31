#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        string s,t;
        cin >> s >> t;

        int lens = (int)s.size();
        int lent = (int)t.size();
        int Max = lcm(lens,lent);

        int need1 = Max / lens;
        int need2 = Max / lent;

        string ss = s;
        string tt = t;
        for (int i = 0;i < need1 - 1;i++) {
            s += ss;
        }

        for (int i = 0;i < need2 - 1;i++) {
            t += tt;
        }

        if (s == t) {
            cout << s << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}