#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int g,x,y,z;
    cin >> g >> x >> y >> z;

    int gg;
    vector<vector<int>> p(n + 1,vector<int>(m + 1,0));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (i == 1 && j == 1) {
                p[i][j] = g;
            }
            else {
                gg = (g * x + y) % z;
                p[i][j] = gg;
                g = gg;
            }
        }
    }

    vector<vector<int>> Min(n + 1,vector<int>(m + 1,0));

    for (int i = 1;i <= n;i++) {
        deque<int> q;
        for (int j = 1;j <= m;j++) {
            while (!q.empty() && q.front() <= j - b) {
                q.pop_front();
            }
            while (!q.empty() && p[i][q.back()] >= p[i][j]) {
                q.pop_back();
            }
            q.push_back(j);

            if(j >= b) {
                Min[i][j] = p[i][q.front()];
            }
        }
    }

    int ans = 0;

    for (int j = b;j <= m;j++) {
        deque<int> q;
        for (int i = 1;i <= n;i++) {
            while (!q.empty() && q.front() <= i - a) {
                q.pop_front();
            }
            while (!q.empty() && Min[q.back()][j] >= Min[i][j]) {
                q.pop_back();
            }
            q.push_back(i);

            if (i >= a) {
                ans += Min[q.front()][j];
            }
        }
    }

    cout << ans << "\n";
}