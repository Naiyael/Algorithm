#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int Max = 0;
    int Min = 1e9 + 10;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        Min = min(a[i],Min);
        Max = max(a[i],Max);
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 2;

    if (Max != a.front() && Max != a.back()) {
        ans++;
    }
    if (Min != a.front() && Min != a.back()) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}