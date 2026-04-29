#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
bool vis[N] = {false};

int main() {
    int n,m;
    cin >> n >> m;
    if (n >= m) {
        cout << n - m << endl;
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({n,0});
    vis[n] = true;
    while (!q.empty()) {
        int sum = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (sum == m) {
            cout << steps << endl;
            return 0;
        }

        if (sum * 2 <= 1e4 + 10 && !vis[sum * 2]) {
            vis[sum * 2] = true;
            q.push({sum * 2,steps + 1});
        }

        if (sum - 1 > 0 && !vis[sum - 1]) {
            vis[sum - 1] = true;
            q.push({sum - 1,steps + 1});
        }
    }
    return 0;
}