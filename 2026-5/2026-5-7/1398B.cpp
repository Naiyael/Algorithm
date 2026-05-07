#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> a;
        for (int i = 0;i < (int)s.size();i++) {
            if (s[i] == '1') {
                int j = i;
                while (j + 1 < (int)s.size() && s[j + 1] == '1') {
                    j++;
                }
                a.push_back(j - i + 1);
                i = j;
            }
        }
        sort(a.rbegin(),a.rend());
        int ans = 0;
        for (int i = 0;i < (int)a.size();i += 2) {
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}