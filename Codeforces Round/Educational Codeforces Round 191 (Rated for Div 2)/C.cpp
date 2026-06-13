#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        string ans(n,'0');

        while (k > 0) {
            vector<int> p;
            for (int i = 0;i < n;i++) {
                if (ans[i] == '0') {
                    p.push_back(i);
                }
            }

            int m = p.size();
            vector<int> S(m + 1,0);
            int min_S = 0;
            int first_min_j = 0;
            int last_min_j = 0;

            for (int j = 1; j <= m; j++) {
                S[j] = S[j - 1] + (s[p[j - 1]] == '(' ? 1 : -1);
                if (S[j] < min_S) {
                    min_S = S[j];
                    first_min_j = j;
                    last_min_j = j;
                } else if (S[j] == min_S) {
                    last_min_j = j;
                }
            }

            int target = -1;

            for (int j = 1; j <= last_min_j; j++) {
                if (s[p[j - 1]] == '(') {
                    target = p[j - 1];
                    break;
                }
            }

            if (target == -1) {
                for (int j = m; j > first_min_j; j--) {
                    if (s[p[j - 1]] == ')') {
                        target = p[j - 1];
                        break;
                    }
                }
            }

            if (target != -1) {
                ans[target] = '1';
                k--;
            }
            else {
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}