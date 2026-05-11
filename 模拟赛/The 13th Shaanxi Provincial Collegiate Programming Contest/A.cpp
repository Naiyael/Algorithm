#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

signed main() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    vector<int> w(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }

    vector<vector<int>> pos(n + 1);
    for (int i = 1;i <= n;i++) {
        pos[c[i]].push_back(i);
    }

    vector<int> ans;
    for (int i = 1;i <= n;i++) {
        vector<int> cnt = pos[i];

        if (cnt.empty()) {
            ans.push_back(w[i] + n);
            continue;
        }

        if (cnt.size() == n) {
            ans.push_back(0);
            continue;
        }

        vector<pair<int,int>> a;
        if (cnt.front() > 1) {
            a.push_back(make_pair(1,cnt.front() - 1));
        }
        for (int j = 0;j < (int)cnt.size() - 1;j++) {
            if (cnt[j + 1] > cnt[j] + 1) {
                a.push_back(make_pair(cnt[j] + 1,cnt[j + 1] - 1));
            }
        }
        if (cnt.back() < n) {
            a.push_back(make_pair(cnt.back() + 1,n));
        }

        int m = a.size();
        int nn = n - cnt.size();
        int cost = m * w[i] + nn;

        int q = 0;
        int sum = 0;
        for (int j = 0;j < m - 1;j++) {
            int gap = a[j + 1].first - a[j].second - 1;
            if (gap < w[i]) {
                q++;
                sum += gap;
            }
        }
        ans.push_back(cost - q * w[i] + sum);
    }
    for (int i = 0;i < n;i++) {
        cout << ans[i] << " ";
    }
}