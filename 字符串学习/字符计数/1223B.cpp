#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string s,t;
        cin >> s >> t;
        set<char> cnt1,cnt2;
        int len = (int)s.size();

        for (int i = 0;i < len;i++) {
            cnt1.insert(s[i]);
            cnt2.insert(t[i]);
        }

        bool flag = true;
        for (auto c : cnt1) {
            if (cnt2.count(c)) {
                flag = false;
            }
        }

        if (flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}