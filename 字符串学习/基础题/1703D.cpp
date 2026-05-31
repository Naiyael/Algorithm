#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n + 1);
        string ans(n + 1,'0');
        map<string,int> cnt;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (!cnt[a[i]]) {
                cnt[a[i]] = 1;
            }
            else {
                cnt[a[i]]++;
            }
        }

        for (int i = 1;i <= n;i++) {
            int len = (int)a[i].size();
            for (int j = 1;j < len;j++) {
                string s1 = a[i].substr(0,j);
                string s2 = a[i].substr(j);
                if (cnt[s1] && cnt[s2]) {
                    ans[i] = '1';
                }
            }
        }
        for (int i = 1;i <= n;i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}