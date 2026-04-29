#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int pre[N];
int dist[N];

int find(int x) {
    if (pre[x] == x) return x;

    int root = find(pre[x]);
    dist[x] += dist[pre[x]];
    return pre[x] = root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1;i <= n;i++) {
        pre[i] = i;
        dist[i] = 0;
    }

    for (int i = 1;i <= n;i++) {
        int boss;
        cin >> boss;
        if (boss != -1) {
            pre[i] = boss;
            dist[i] = 1;
        }
    }

    int ans = 0;

    for (int i = 1;i <= n;i++) {
        find(i);
        ans = max(ans, dist[i] + 1);
    }

    cout << ans << endl;

    return 0;
}