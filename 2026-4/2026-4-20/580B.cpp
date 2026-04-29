#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
struct Node {
    int mi,si;
};
Node a[N];

bool cmp(const Node& a,const Node& b) {
    return a.mi < b.mi;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,d;
    cin >> n >> d;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].mi >> a[i].si;
    }
    sort(a + 1,a + n + 1,cmp);

    int cnt = 0;
    int ans = 0;
    int l = 1;
    for (int i = 1;i <= n;i++) {
        cnt += a[i].si;
        while (a[i].mi - a[l].mi >= d) {
            cnt -= a[l].si;
            l++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}