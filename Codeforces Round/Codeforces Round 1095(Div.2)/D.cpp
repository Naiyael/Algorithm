#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int Maxodd = 0;
        int Minodd = 1e8;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                Maxodd = max(Maxodd,a[i]);
                Minodd = min(Minodd,a[i]);
            }
        }
    }
    return 0;
}