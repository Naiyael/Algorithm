#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s,t;
        cin >> s >> t;

        int len1 = (int)s.size();
        vector<pair<int,int>> cnt1;
        for (int i = 0;i < len1;i++) {
            int l = i;
            int r = i;
            while (r + 1 < len1 && s[r] == s[r + 1]) {
                r++;
            }
            i = r;
            cnt1.push_back(make_pair(l,r));
        }

        int len2 = (int)t.size();
        vector<pair<int,int>> cnt2;
        for (int i = 0;i < len2;i++) {
            int l = i;
            int r = i;
            while (r + 1 < len2 && t[r] == t[r + 1]) {
                r++;
            }
            i = r;
            cnt2.push_back(make_pair(l,r));
        }

        bool flag = false;
        if (cnt1.size() != cnt2.size()) {
            cout << "NO" << endl;
            continue;
        }

        int nn = (int)cnt1.size();
        for (int i = 0;i < nn;i++) {
            int lens = cnt1[i].second - cnt1[i].first + 1;
            int lent = cnt2[i].second - cnt2[i].first + 1;
            if (lens > lent) {
                flag = true;
                break;
            }
            if (s[cnt1[i].first] != t[cnt2[i].first]) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}