#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    vector<int> diff(n + 2,0);
    for (int i = 0;i < q;i++) {
        int l,r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> cnt(n + 1,0);
    for (int i = 1;i <= n;i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    sort(a.begin() + 1,a.end(),greater<int>());
    sort(cnt.begin() + 1,cnt.end(),greater<int>());

    int ans = 0;
    for (int i = 1;i <= n;i++) {
        if (cnt[i] == 0) {
            break;
        }
        ans += a[i] * cnt[i];
    }
    cout << ans << endl;
}