#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

int pre[MAXN];
int nums[MAXN];

int find(int v) {
    if (v == pre[v]) {
        return v;
    }
    return pre[v] = find(pre[v]);
}

void join(int x,int y) {
    int fx = find(x);
    int fy = find(y);

    if (fx != fy) {
        if (nums[fx] < nums[fy]) {
            swap(fx,fy);
        }
        pre[fy] = fx;
        nums[fx] += nums[fy];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        pre[i] = i;
        nums[i] = 1;
    }

    for (int i = 0;i < m;i++) {
        int k;
        cin >> k;
        if (k > 0) {
            int ki;
            cin >> ki;

            for (int j = 1; j < k; j++) {
                int user;
                cin >> user;
                join(ki, user);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << nums[find(i)] << " ";
    }
    cout << endl;

    return 0;
}