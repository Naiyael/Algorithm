#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int pre[N];
bool vis[N];

struct Node {
    int x,y;
};
Node a[N];

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
    int n;
    cin >> n;
    init(n);
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> a[i].x >> a[i].y;
    }

    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (a[i].x == a[j].x || a[i].y == a[j].y) {
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