#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n,m;
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
    pre[fx] = fy;
}

int main() {
    cin >> n >> m;
    init(n);
    while (m--) {
        int x,y;
        cin >> x >> y;
        join(x,y);
    }

    long long ans = 1;
    for (int i = 1;i <= n;i++) {
        if (find(i) != i) {
            ans *= 2;
        }
    }
    cout << ans << endl;
    return 0;
}