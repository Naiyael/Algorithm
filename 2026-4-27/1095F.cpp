#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int pre[N];
int a[N];
struct Edge {
    int l,r,val;
};

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

signed main() {
    int n,m;
    cin >> n >> m;
    init(n);
    vector<Edge> edges;
    int ans = 0;
    int cnt = 0;
    int index  = 1;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] < a[index]) {
            index = i;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (i != index) {
            edges.push_back({index,i,a[index] + a[i]});
        }
    }

    for (int i = 1;i <= m;i++) {
        int l,r,val;
        cin >> l >> r >> val;
        edges.push_back({l,r,val});
    }

    sort(edges.begin(),edges.end(),[](const Edge& a,const Edge& b) {
       return a.val < b.val;
    });

    for (Edge edge : edges) {
        int x = find(edge.l);
        int y = find(edge.r);

        if (x != y) {
            ans += edge.val;
            join(x,y);
            cnt++;
        }
        if (cnt == n - 1) {
            break;
        }
    }
    cout << ans << endl;
}