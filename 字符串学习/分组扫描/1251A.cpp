#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        set<char> ans;
        int n = (int)s.size();

        for (int i = 0;i < n;i++) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                i++;
            } 
            else {
                ans.insert(s[i]);
            }
        }

        for (auto c : ans) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}