#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N][N];
int main() {
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            a[i][j] = cnt;
            cnt++;
        }
    }
    int ans = 0;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == j) {
                ans += a[i][j];
            }
        }
    }
    cout << ans * 2 << endl;
    return 0;
}