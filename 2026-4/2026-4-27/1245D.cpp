#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2010;
const int INF = 2e18;
int c[N];
int k[N];

signed main() {
    int n;
    cin >> n;
    vector<pair<int,int>> city(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> city[i].first >> city[i].second;
    }
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> k[i];
    }

    vector<int> minDist(n + 1);
    vector<bool> vis(n + 1,false);
    vector<int> parent(n + 1,0);

    for (int i = 1;i <= n;i++) {
        minDist[i] = c[i];
    }

    int ans = 0;
    vector<int> stations;
    vector<pair<int,int>> connections;

    for (int i = 1;i <= n;i++) {
        int cur = -1;
        int minVal = INF;

        for (int i = 1;i <= n;i++) {
            if (!vis[i] && minDist[i] < minVal) {
                minVal = minDist[i];
                cur = i;
            }
        }

        vis[cur] = true;
        ans += minVal;

        if (parent[cur] == 0) {
            stations.push_back(cur);
        }
        else {
            connections.push_back({cur,parent[cur]});
        }

        for (int i = 1;i <= n;i++) {
            if (!vis[i]) {
                int cost = (k[cur] + k[i]) * (abs(city[cur].first - city[i].first) + abs(city[cur].second - city[i].second));
                if (cost < minDist[i]) {
                    minDist[i] = cost;
                    parent[i] = cur;
                }
            }
        }
    }

    cout << ans << endl;

    cout << (int)stations.size() << endl;
    for (int i :stations) {
        cout << i << " ";
    }
    cout << endl;

    cout << (int)connections.size() << endl;
    for (auto i : connections) {
        cout << i.first << " " << i.second << endl;
    }
}