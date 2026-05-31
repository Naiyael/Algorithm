#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string t;
        cin >> t;
        int n = (int)t.size();
        bool flag0 = false;
        bool flag1 = false;

        for (char c : t) {
            if (c == '0') {
                flag0 = true;
            }
            else {
                flag1 = true;
            }
        }

        if (!flag0 || !flag1) {
            cout << t << "\n";
        }
        else {
            for (int i = 0;i < n;i++) {
                cout << "10";
            }
            cout << "\n";
        }
    }
    return 0;
}