#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<string> dp(8,"");

    for (char c : s) {
        int d = c - '0';
        vector<string> ndp = dp;
        ndp[d % 8] = string(1,c);

        for (int j = 0;j < 8;j++) {
            if (dp[j] != "" && dp[j] != "0") {
                int cnt = (j * 10 + d) % 8;
                ndp[cnt] = dp[j] + c;
            }
        }
        dp = ndp;
    }

    if (dp[0] != "") {
        cout << "YES" << endl << dp[0] << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}