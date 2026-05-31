#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int l = 0;
    int r = s.size() - 1;
    vector<int> ans;

    while (l < r) {
        while (l < r && s[l] != '(') {
            l++;
        }
        while (l < r && s[r] != ')') {
            r--;
        }

        if (l < r) {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            l++;
            r--;
        }
    }

    if (ans.empty()) {
        cout << 0 << "\n";
    }
    else {
        cout << 1 << "\n";
        cout << ans.size() << "\n";

        sort(ans.begin(), ans.end());
        for (int i = 0;i < ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}