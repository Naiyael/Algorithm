#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int l = 0;
        int r = n - 1;
        bool flag = false;

        while (l < r) {
            if (s[l] + 1 == s[r] - 1 || s[l] - 1 == s[r] - 1
                || s[l] + 1 == s[r] + 1 || s[l] - 1 == s[r] + 1) {
                l++;
                r--;
            }
            else {
                flag = true;
                   break;
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