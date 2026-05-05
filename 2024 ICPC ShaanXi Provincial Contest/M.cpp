#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int, int>> cells;
    for (int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;

        int u = x + y;
        int v = x - y;
        
        cells.insert({u - 1, v - 1});
        cells.insert({u, v - 1});
        cells.insert({u - 1, v});
        cells.insert({u, v});
    }
    double ans = cells.size() * 0.5;
    cout << ans << endl;
    return 0;
}