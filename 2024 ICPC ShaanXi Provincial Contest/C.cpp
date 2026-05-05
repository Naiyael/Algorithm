#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ind(2 * n + 1,0);

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        ind[a[i]]++;
    }

    vector<int> dp(2 * n + 1,0);
    for (int i = 1;i <= n;i++) {
        dp[i] = 1;
    }

    queue<int> q;
    for (int i = 1;i <= 2 * n;i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u > n) continue;

        int v = a[u];
        if (v <= n) {
            dp[v] = max(dp[v],dp[u] + 1);
        } else {
            dp[v] = max(dp[v],dp[u]);
        }

        ind[v]--;
        if (ind[v] == 0) {
            q.push(v);
        }
    }

    int ans = 0;
    for (int i = n + 1;i <= 2 * n;i++) {
        ans += dp[i];
    }

    for (int i = 1;i <= n;i++) {
        if (ind[i] > 0) {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}