#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,k;
int a[N];
int ans = 2e18;
int dif[N];

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i < n;i++) {
        dif[i] = a[i + 1] - a[i];
    }

    deque<int> q;
    for (int r = 2;r <= n;r++) {
        int index = r - 1;
        while (!q.empty() && dif[q.back()] >= dif[index]) {
            q.pop_back();
        }
        q.push_back(index);

        int l = r - k + 1;
        while (!q.empty() && q.front() < l) {
            q.pop_front();
        }

        if (r >= k) {
            int Max = a[r] - a[l];
            int Min = dif[q.front()];
            ans = min(ans,Max * Min);
        }
    }

    cout << ans << endl;
}