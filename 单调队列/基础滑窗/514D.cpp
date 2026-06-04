#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1,vector<int>(m + 1,0));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }

    vector<deque<int>> q(m + 1);
    int l = 1;
    int Max = 0;
    vector<int> ans(m + 1,0);

    for (int i = 1;i <= n;i++) {

        for (int j = 1;j <= m;j++) {
            while (!q[j].empty() && a[q[j].back()][j] <= a[i][j]) {
                q[j].pop_back();
            }
            q[j].push_back(i);
        }

        long long cur = 0;
        for (int j = 1;j <= m;j++) {
            cur += a[q[j].front()][j];
        }

        while (cur > k && l <= i) {
            l++;

            for (int j = 1;j <= m;j++) {
                if (!q[j].empty() && q[j].front() < l) {
                    q[j].pop_front();
                }
            }

            cur = 0;
            for (int j = 1;j <= m;j++) {
                if (!q[j].empty()) {
                    cur += a[q[j].front()][j];
                }
            }
        }

        if (i - l + 1 > Max) {
            Max = i - l + 1;
            for (int j = 1;j <= m;j++) {
                if (!q[j].empty()) {
                    ans[j] = a[q[j].front()][j];
                }
                else {
                    ans[j] = 0;
                }
            }
        }
    }

    for (int j = 1;j <= m;j++) {
        cout << ans[j] << " ";
    }
    cout << "\n";

    return 0;
}