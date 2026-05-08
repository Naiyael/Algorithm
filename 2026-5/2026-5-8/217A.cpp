#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int x,y;
int pre[N];

void init(int n) {
    for (int i = 1;i <= n;i++) {
        pre[i] = i;
    }
}

int find(int x) {
    if (pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

void join(int x,int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    pre[fy] = fx;
}

int main() {
    cin >> n;
    init(n);
    vector<pair<int,int>> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (a[i].first == a[j].first || a[i].second == a[j].second) {
                join(i,j);
            }
        }
    }

    int ans = 0;
    for (int i = 1;i <= n;i++) {
        if (find(i) == i) {
            ans++;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}