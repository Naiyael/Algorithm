#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
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
    int n;
    cin >> n;
    init(n);
    vector<pair<int,int>> path;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            path.push_back({a,b});
        }
        else {
            join(a,b);
        }
    }

    vector<int> leaders;

    for (int i = 1;i <= n;i++) {
        if (find(i) == i) {
            leaders.push_back(i);
        }
    }
    cout << path.size() << endl;
    for (int i = 0;i < (int)path.size();i++) {
        cout << path[i].first << " " << path[i].second << " "
        << leaders[0] << " " << leaders[i + 1] << endl;
    }
    return 0;
}