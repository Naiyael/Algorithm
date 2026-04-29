#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1;i <= k;i++) {
        sum += a[i];
    }

    int sum0 = sum;
    int ans = 1;
    for (int i = 2;i <= n - k + 1;i++) {
        sum = sum - a[i - 1] + a[i + k - 1];
        if (sum < sum0) {
            sum0 = sum;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}