#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<string> a(n);
    vector<string> l;
    vector<string> r;
    string middle = "";

    map<string,int> cnt;

    for (int i = 0;i < n;i++) {
        cin >> a[i];
        cnt[a[i]] = 1;
    }

    for (int i = 0;i < n;i++) {
        string s = a[i];
        string rev = s;
        reverse(rev.begin(),rev.end());

        if (s == rev) {
            middle = s;
        }
        else if (cnt[rev] == 1) {
            l.push_back(s);
            r.push_back(rev);
            cnt[s] = 0;
            cnt[rev] = 0;
        }
    }

    string ans = "";
    for (int i = 0;i < (int)l.size();i++) {
        ans += l[i];
    }

    ans += middle;

    for (int i = (int)r.size() - 1;i >= 0;i--) {
        ans += r[i];
    }
    
    cout << ans.size() << "\n";

    if (ans.size() > 0) {
        cout << ans << "\n";
    }

    return 0;
}