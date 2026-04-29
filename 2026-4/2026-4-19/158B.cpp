#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int c[5] = {0};
    while (n--) {
        cin >> x;
        c[x]++;
    }
    int cnt = max(0,c[1] - c[3]);

    int ans = c[4] + c[3] + (c[2] * 2 + cnt + 3) / 4;

    cout << ans << endl;
    return 0;
}