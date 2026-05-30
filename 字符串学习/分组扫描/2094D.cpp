#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string p,s;
        cin >> p >> s;

        int n = p.size();
        int m = s.size();

        int i = 0,j = 0;
        bool flag = true;

        while (i < n && j < m) {
            if (p[i] != s[j]) {
                flag = false;
                break;
            }

            char cur = p[i];
            int count1 = 0;
            int count2 = 0;

            while (i < n && p[i] == cur) {
                count1++;
                i++;
            }

            while (j < m && s[j] == cur) {
                count2++;
                j++;
            }

            if (count2 < count1 || count2 > count1 * 2) {
                flag = false;
                break;
            }
        }

        if (i != n || j != m) {
            flag = false;
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