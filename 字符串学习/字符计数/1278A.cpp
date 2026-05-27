#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string p,h;
        cin >> p >> h;
        int len1 = (int)p.size();
        int len2 = (int)h.size();

        map<char,int> cnt1;

        if (len1 == len2 && h == p) {
            cout << "YES" << endl;
            continue;
        }

        if (len1 > len2) {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0;i < len1;i++) {
            cnt1[p[i]]++;
        }

        bool flag = false;
        for (int i = 0;i <= len2 - len1;i++) {
            string s = h.substr(i,len1);
            map<char,int> cnt2;
            for (auto c : s) {
                cnt2[c]++;
            }

            if (cnt1 == cnt2) {
                flag = true;
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
    return 0;
}