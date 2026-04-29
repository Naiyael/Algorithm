#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> in(n + 1,0);
        vector<vector<int>> adj(n + 1);
        vector<int> dp(n + 1, 1);

        for (int i = 1;i <= n;i++) {
            int ki;
            cin >> ki;
            in[i] += ki;
            for (int j = 0;j < ki;j++) {
                int need;
                cin >> need;
                adj[need].push_back(i);
            }
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            if (in[i] == 0) q.push(i);
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();
            cnt++;
            for (int i = 0;i < adj[cur].size();i++) {
                int node = adj[cur][i];

                if (cur < node) {
                    dp[node] = max(dp[node],dp[cur]);
                }
                else {
                    dp[node] = max(dp[node],dp[cur] + 1);
                }
                in[node]--;
                if (in[node] == 0) {
                    q.push(node);
                }
            }
        }
        if (cnt < n) {
            cout << -1 << endl;
        }
        else {
            int ans = 0;
            for (int i = 1;i <= n;i++) {
                ans = max(ans,dp[i]);
            }
            cout << ans << endl;
        }
    }

    return 0;
}