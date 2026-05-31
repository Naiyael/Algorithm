#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = (int)s.size();
        stack<char> cnt;
        for (int i = 0;i < n;i++) {
            if (s[i] == 'A') {
                cnt.push(s[i]);
            }
            else {
                if (!cnt.empty()) {
                    cnt.pop();
                }
                else {
                    cnt.push(s[i]);
                }
            }
        }
        cout << cnt.size() << endl;
    }
    return 0;
}