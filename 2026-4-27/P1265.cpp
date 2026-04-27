#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<pair<int,int>> grid(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> grid[i].first >> grid[i].second;
    }

    vector<double> minDist(n + 1,1e18);
    vector<bool> vis(n + 1,false);
    for (int i = 1;i < n;i++) {
        int cur = -1;
        int minVal = 2e18;
        for (int j = 1;j <= n;j++) {
            if (!vis[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }
        vis[cur] = true;

        for (int j = 1;j <= n;j++) {
            if (!vis[j]) {
                int x = abs(grid[j].first - grid[cur].first) * abs(grid[j].first - grid[cur].first);
                int y = abs(grid[j].second - grid[cur].second) * abs(grid[j].second - grid[cur].second);
                double dist = pow((x + y),0.5);
                if (dist < minDist[j]) {
                    minDist[j] = dist;
                }
            }
        }
    }
    double ans = 0.0;
    for (int i = 2;i <= n;i++) {
        ans += minDist[i];
    }
    cout << fixed << setprecision(2) << ans << endl;
}