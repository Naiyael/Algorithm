#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int c[N];
int n,m;

struct Node {
    int id;
    int cost;
};
Node pre[N];

void init(int n) {
    for (int i = 1;i <= n;i++) {
        pre[i].id = i;
    }
}

int find(int x) {
    if (pre[x].id == x) return x;
    return pre[x].id = find(pre[x].id);
}

void join(int x,int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (pre[x].cost < pre[y].cost) {
        pre[y].id = x;
    }
    else {
        pre[x].id = y;
    }
}

signed main() {
    cin >> n >> m;
    init(n);
    for (int i = 1;i <= n;i++) {
        cin >> pre[i].cost;
    }

    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        join(x,y);
    }

    int cost = 0;
    for (int i = 1;i <= n;i++) {
        if (find(i) == i) {
            cost += pre[i].cost;
        }
    }
    cout << cost << endl;
}