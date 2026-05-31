#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int l = 0;
        int r = n - 1;

        while (l < n && s[l] == '0') {
            l++;
        }

        while (r >= 0 && s[r] == '1') {
            r--;
        }

        if (l >= r) {
            cout << s << "\n";
        }
        else {
            for (int i = 0;i < l;i++) {
                cout << '0';
            }

            cout << '0';

            for (int i = r + 1;i < n;i++) {
                cout << '1';
            }

            cout << "\n";
        }
    }
    return 0;
}