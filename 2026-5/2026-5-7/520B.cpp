#include <bits/stdc++.h>
using namespace std;
const int MAX = 20005;
int n,m;
int a[MAX];
int ans = 1e9;

void dfs(int curr, int step) {
    if (step >= a[curr]) return;
    a[curr] = step;

    if (step >= ans) return;

    if (curr == m) {
        ans = min(ans,step);
        return;
    }

    if (curr > m) {
        ans = min(ans,step + (curr - m));
        return;
    }

    if (curr * 2 < MAX) {
        dfs(curr * 2, step + 1);
    }

    if (curr - 1 > 0) {
        dfs(curr - 1, step + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < MAX; i++) {
        a[i] = 1e9;
    }

    dfs(n, 0);

    cout << ans << endl;
    return 0;
}