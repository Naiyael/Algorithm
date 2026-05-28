#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string p,s;
        cin >> p >> s;
        int len1 = (int)p.size();
        int len2 = (int)s.size();

        vector<pair<int,int>> cnt1;
        for (int i = 0;i < len1;i++) {
            int l = i;
            int r = i;
            while (r + 1 < len1 && p[r] == p[r + 1]) {
                r++;
            }
            cnt1.push_back(make_pair(l,r));
            i = r;
        }

        vector<pair<int,int>> cnt2;
        for (int i = 0;i < len2;i++) {
            int l = i;
            int r = i;
            while (r + 1 < len2 && s[r] == s[r + 1]) {
                r++;
            }
            cnt2.push_back(make_pair(l,r));
            i = r;
        }

        int lenp = (int)cnt1.size();
        int lens = (int)cnt2.size();
        if (lenp != lens) {
            cout << "NO" << endl;
            continue;
        }

        for ()
    }
    return 0;
}