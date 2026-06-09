#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> sum(n + 1,0);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    deque<int> q;
    int ans = -2e9;
    q.push_back(0);

    for (int i = 1;i <= n;i++) {
        while (!q.empty() && q.front() < i - m) {
            q.pop_front();
        }

        if (!q.empty()) {
            ans = max(ans,sum[i] - sum[q.front()]);
        }

        while (!q.empty() && sum[q.back()] >= sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << ans << "\n";

    return 0;
}