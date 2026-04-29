#include <bits/stdc++.h>
using namespace std;
string s;

bool check(int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        else {
            l++;
            r--;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        map<char,int> cnt;
        int end = (int)s.size();
        for (int i = 0;i < (int)s.size();i++) {
            if (!cnt[s[i]]) {
                cnt[s[i]] = 1;
            }
            else {
                end = i;
                break;
            }
        }
        bool flag = false;
        for (int i = 0;i < end && i < (int)s.size() - 1;i++) {
            int l = i + 1;
            int r = (int)s.size() - 1;
            if (check(l,r)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "HE" << endl;
        }
        else {
            cout << "NaN" << endl;
        }
    }
    return 0;
}