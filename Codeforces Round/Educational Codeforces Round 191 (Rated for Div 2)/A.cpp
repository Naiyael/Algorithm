#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,x,y,z;
        cin >> n >> x >> y >> z;
        int nn = n;
        int cnt1 = 0,cnt2 = 0;

        while (n > 0) {
            n = n - x - y;
            cnt1++;
        }

        while (nn > 0) {
            if (z > 0) {
                nn = nn - x;
                z--;
                cnt2++;
            }
            else {
                nn = nn - x - 10 * y;
                cnt2++;
            }
        }
        cout << min(cnt1,cnt2) << "\n";
    }
    return 0;
}