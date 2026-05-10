#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 510;
int dist[N][N];
int order[N];
int ans[N];
bool active[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 1;i <= n;i++) {
        cin >> order[i];
    }

    for (int step = n;step >= 1;step--) {
        int k = order[step];
        active[k] = true;

        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int sum = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (active[i] && active[j]) {
                    sum += dist[i][j];
                }
            }
        }

        ans[step] = sum;
    }

    for (int i = 1;i <= n;i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
}