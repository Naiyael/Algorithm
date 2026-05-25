#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "";
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0) s += "F";
        if (i % 5 == 0) s += "B";
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        string a;
        cin >> n >> a;

        if (s.find(a) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}