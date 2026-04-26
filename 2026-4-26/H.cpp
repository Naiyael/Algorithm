#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        if (k > 2 * n) {
            cout << 0 << " " << 2 * n << endl;
        }
        else {
            cout << ceil(n - (k - 1) * 0.5) << " "
            << ceil(n - (k - 1) * 0.5 + k - 1) << endl;
        }
    }
    return 0;
}