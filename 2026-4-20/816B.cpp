#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int diff[N],add[N];

signed main() {
    int n,k,q;
    cin >> n >> k >> q;
    for (int i = 0;i < n;i++) {
        int l,r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    for (int i = 1;i <= 2e5;i++) {
        diff[i] += diff[i - 1];
        if (diff[i] >= k) {
            add[i] = add[i - 1] + 1;
        }
        else {
            add[i] = add[i - 1];
        }
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << add[r] - add[l - 1] << endl;
    }
}