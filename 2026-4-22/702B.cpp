#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    long long ans = 0;
    map<int,int> cnt;

    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 30;j++) {
            int k = 1 << j;
            int need = k - a[i];

            if (cnt.count(need)) {
                ans += cnt[need];
            }
        }
        cnt[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}